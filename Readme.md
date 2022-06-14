# Corner detection for chessboaard/checkerboard
Corner detection code adapted from https://github.com/hengli/camodocal

## Building the code (C++)
```
mkdir build
cd build
cmake ..
make
```

## Running the code (C++)
```
./test_chessboard <directory_path>
```
There should be a file named ```image_paths.txt``` int the directory path containing the absolute path of all the images in the directory.
To generate the image_paths.txt file, run the following command:
```
find <directory_path> -name "*.<extension>" > <directory_path>/image_paths.txt

OR

python image_paths.py --directory_path <directory_path> --extension <extension>
```
## Installing the package as python package
```
pip install git+https://github.com/sandeepnmenon/chessboard_detection.git
```
See ```tests/test.py``` for python module usage
