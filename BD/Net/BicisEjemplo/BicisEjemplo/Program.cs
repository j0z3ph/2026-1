using BicisEjemplo.Models;
using Microsoft.EntityFrameworkCore;
using BicisEjemplo.Data;
using Microsoft.AspNetCore.Identity;
using BicisEjemplo.Areas.Identity.Data;

namespace BicisEjemplo
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);

            // Add services to the container.
            builder.Services.AddControllersWithViews();

            // Agregamos el servicio de base de datos
            builder.Services.AddDbContext<BikesDbContext>(options => options.UseSqlServer(builder.Configuration.GetConnectionString("MiBD")));

            builder.Services.AddDefaultIdentity<BicisEjemploUser>(
                options => options.SignIn.RequireConfirmedAccount = false)
                .AddRoles<IdentityRole>()
                .AddEntityFrameworkStores<BikesDbContext>();
            
            
            
            
            var app = builder.Build();

            // Configure the HTTP request pipeline.
            if (!app.Environment.IsDevelopment())
            {
                app.UseExceptionHandler("/Home/Error");
                // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
                app.UseHsts();
            }

            app.UseHttpsRedirection();
            app.UseRouting();

            app.UseAuthorization();

            app.MapStaticAssets();
            app.MapControllerRoute(
                name: "default",
                pattern: "{controller=Home}/{action=Index}/{id?}")
                .WithStaticAssets();
            app.MapRazorPages();

            app.Run();
        }
    }
}
