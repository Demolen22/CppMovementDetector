# CppMovementDetector

Simple movement detector using OpenCV, in c++.
Program uses view captured from webcamera and marks with green colour contour of moving object or person.
Additional feature is possibility of saving current frame by pressing "s".

It captures two frames from camera, turns them into black-white scale and subtracts the pixels. The result is the image of object that has moved.
Next steps are blurring the image using gaussian blur and detecting edges with opencv canny function. When edges are detected they are dilated.
Then contour of the object is found and marked with green colour on the original image.
