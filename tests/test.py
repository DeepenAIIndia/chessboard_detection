import os
import pyChessBoardDetector

def test_binding():
    assert pyChessBoardDetector.test_bindings() == "Hello Binders!","Binding Test Failed"
    print("Binding Test Successful")

def test_cornerdetector():
    images_path = []
    file_path = os.path.dirname(os.path.realpath(__file__))
    image_path = os.path.join(file_path,"IMG_3715.jpg")
    images_path.append(image_path)
    image_path = os.path.join(file_path,"IMG_3134.jpg")
    images_path.append(image_path)
    image_path = os.path.join(file_path,"IMG_3135.jpg")
    images_path.append(image_path)
    output = pyChessBoardDetector.get_chessboard_corners(images_path,9,7,False)  #example Board Height = 9, Board Width = 7

    for image_path in images_path:
        assert image_path in output, f"{image_path} not found in output"

    for key in output:
        assert len(output[key]) == 63, "Output length is mismatched with total number of corners in image" # 63 ~ 9(Board Height)*7(Board Width)

    print("Corner Detection Sucessful")
    
if __name__ == "__main__":
    test_binding()
    test_cornerdetector()
