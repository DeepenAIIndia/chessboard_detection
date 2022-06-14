import os
import pyChessBoardDetector

def test_binding():
    if(pyChessBoardDetector.test_bindings()== "Hello Binders!"):
        assert pyChessBoardDetector.test_bindings() == "Hello Binders!"
        print("Sucess")
    else:
        print("Fail")


def test_cornerdetector():
    images_path = []
    file_path = os.path.dirname(os.path.realpath(__file__))
    image_path = os.path.join(file_path,"IMG_3715.jpg")
    images_path.append(image_path)
    image_path = os.path.join(file_path,"IMG_3134.jpg")
    images_path.append(image_path)
    image_path = os.path.join(file_path,"IMG_3135.jpg")
    images_path.append(image_path)
    output = pyChessBoardDetector.get_chessboard_corners(images_path,9,7,False)
    image_path_list = []
    output_image_key_list = []
    for path in sorted(images_path):
        image_path_list.append(path)
    
    for i in sorted(output):
        output_image_key_list.append(i)

    for j in range(0,len(image_path_list)):
        assert image_path_list[j] == output_image_key_list[j]

    print("Sucess From cornerdetector")
    
if __name__ == "__main__":
    test_binding()
    test_cornerdetector()
