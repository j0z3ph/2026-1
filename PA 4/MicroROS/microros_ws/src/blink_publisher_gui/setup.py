from setuptools import find_packages, setup

package_name = 'blink_publisher_gui'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    #packages=[package_name, f"{package_name}.gui"],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jlcruz',
    maintainer_email='jlcruz@ipn.mx',
    description='MicroROS PySide6 example',
    license='MIT',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'blink_gui = blink_publisher_gui.blink_publisher:main'
        ],
    },
)
