import os
import pyChessBoardDetector

def test_binding():
    if(pyChessBoardDetector.test_bindings()== "Hello Binders!"):
        print("Sucess")
    else:
        print("Fail")


def test_cornerdetector():
    print("Sucess From cornerdetector")
    images_path = []
    file_path = os.path.dirname(os.path.realpath(__file__))
    image_path = os.path.join(file_path,"IMG_3715.jpg")
    images_path.append(image_path)
    image_path = os.path.join(file_path,"IMG_3134.jpg")
    images_path.append(image_path)
    # print("File Path:",image_path)
    output = pyChessBoardDetector.get_chessboard_corners(images_path,9,7,False)
    # print("output= ",output)



if __name__ == "__main__":
    test_binding()
    test_cornerdetector()