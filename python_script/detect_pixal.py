from PIL import Image


def get_black_pixel_coordinates(image_path):
    # Open the image using Pillow
    image = Image.open(image_path)

    # Get the width and height of the image
    width, height = image.size
    curr = (255, 255, 255)
    x_curr = 0
    y_curr = 0
    # Loop through each pixel to find the black pixel
    for x in range(width):
        for y in range(height):
            # Get the pixel value at (x, y)
            pixel = image.getpixel((x, y))
            if pixel < curr:
                curr = pixel
                x_curr = x
                y_curr = y
    return x_curr, y_curr

origin_pixel_coordinates = get_black_pixel_coordinates('front3.png')

X2, Y2 = [0, 0]
if origin_pixel_coordinates:
    x2, y2 = origin_pixel_coordinates
    print(f"The origin pixel is at coordinates (x: {x2}, y: {y2})")
else:
    print("No black pixel found in the image.")

screen = Image.open('back_reflact_front3.png')

# Get the width and height of the image
windowWidth, windowHeight = screen.size
x3 = windowWidth - x2 - 1
y3 = y2
print(f"The reflected pixel is expected to be at coordinates (x: {x3}, y: {y3})")

reflect_pixel_coordinates = get_black_pixel_coordinates('back_reflact_front2.png')

x1, y1 = [0, 0]
if reflect_pixel_coordinates:
    x1, y1 = reflect_pixel_coordinates
    print(f"The reflect pixel is at coordinates (x: {x1}, y: {y1})")
else:
    print("No black pixel found in the image.")

print("")

if x1 == x3 and y1 == y3:
    print("Success!")
    print("The reflected pixel is at the expected position")
