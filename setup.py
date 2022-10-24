from distutils.core import setup, Extension

module = Extension("cmath_func", sources=["module.c"])

setup(
    name="cmath_func module",
    description="cmath_func module, just for learning purposes.",
    ext_modules=[module]
)