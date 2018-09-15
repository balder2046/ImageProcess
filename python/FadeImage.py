import cv2
def getFadeScale(x,borderscale):
    if x < borderscale:
        return x / borderscale
    if x > 1.0 - borderscale:
        return (1.0 - x) / borderscale
    return 1.0
def fadeImage(orgimage,borderscale):
    shape = orgimage.shape
    width = shape[1]
    height = shape[0]
    for y in range(0,height):
        for x in range(0,width):
            xscale = x / float(width)
            scale = getFadeScale(xscale,borderscale)
            for channel in range(0,2):
                orgimage.itemset((y,x,channel),orgimage[y,x,channel] * scale)
                

    pass

def testLoadImage():
    img = cv2.imread("test.png",cv2.IMREAD_COLOR);
    shape = img.shape
    print(shape)
    #bgr
    fadeImage(img,0.2)
    cv2.imshow('image',img)

    cv2.waitKey(0)
    cv2.destoryAllWindows()
    
testLoadImage()
