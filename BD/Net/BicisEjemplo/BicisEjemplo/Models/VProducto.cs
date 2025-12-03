using System;
using System.Collections.Generic;

namespace BicisEjemplo.Models;

public partial class VProducto
{
    public int ProductId { get; set; }

    public string ProductName { get; set; } = null!;

    public string BrandName { get; set; } = null!;

    public string CategoryName { get; set; } = null!;

    public short ModelYear { get; set; }

    public decimal ListPrice { get; set; }
}
