from PIL import Image
import os

files_directory = 'matlab_frames'

files = os.listdir(files_directory)

images = [img for img in files if img.endswith(".png")]

images.sort(key=lambda x: int(x.split('_')[1].split('.')[0])) #sorts the images based on the number written in the image name

#GIF creation

frames = []
for image in images:
    path_image = os.path.join(files_directory, image)
    frame = Image.open(path_image)
    frames. append(frame)

frames[0].save('docs/gif.gif', save_all=True, append_images=frames[1:], duration=500, loop=0)

for image in images:
    if image.endswith(".png"):
        os.remove(os.path.join(files_directory, image))
