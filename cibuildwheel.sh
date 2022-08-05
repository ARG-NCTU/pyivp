pip install cibuildwheel
#export CIBW_BEFORE_ALL='apt install libpng-dev'
export CIBW_BEFORE_ALL=''
export CIBW_BEFORE_BUILD='pip3 install pybind11'
cibuildwheel --platform linux
