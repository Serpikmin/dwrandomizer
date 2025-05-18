from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

dwr_extension = Extension(
    name="dwr",
    sources=["/home/peter/dwrandomizer-wrapper/dwr.pyx"],
    libraries=["/home/peter/dwrandomizer-wrapper/dwr"]
)
setup(
    name="dwr",
    ext_modules=cythonize([dwr_extension])
)