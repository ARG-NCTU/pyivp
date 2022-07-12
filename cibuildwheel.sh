pip install cibuildwheel
#export CIBW_BEFORE_ALL='apt install libpng-dev'
export CIBW_BEFORE_ALL=''
cibuildwheel --platform linux
