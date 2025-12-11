from setuptools import find_packages, setup

package_name = 'blink_publisher'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jlcruz',
    maintainer_email='jlcruz@ipn.mx',
    description='Publish messager to blink ESP32 led',
    license='MIT',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'blink = blink_publisher.blink_publisher:main'
        ],
    },
)
