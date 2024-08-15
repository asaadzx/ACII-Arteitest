from PIL import Image


def resize_image(image_path, new_width=100):
    image = Image.open(image_path)
    width, height = image.size
    aspect_ratio = height / width
    new_height = int(aspect_ratio * new_width)
    resized_image = image.resize((new_width, new_height))
    return resized_image

def image_to_text(image_path, output_file):
    # Open the image and convert it to grayscale
    image = Image.open(image_path).convert('L')
    
    # Get image dimensions
    width, height = image.size
    
    # Save pixel values to a text file
    with open(output_file, 'w') as file:
        file.write(f"{width} {height}\n")  # Write the dimensions first
        for y in range(height):
            for x in range(width):
                pixel_value = image.getpixel((x, y))
                file.write(f"{pixel_value} ")
            file.write("\n")  # Newline after each row


image_to_text(r"C:\Users\DELL\my vscode\cpp for real\convertPicToacii\mages\WhatsApp Image 2024-08-15 at 15.27.20_c298887a.jpg", r"C:\Users\DELL\my vscode\cpp for real\convertPicToacii\mages\image.txt")
