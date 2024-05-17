pkg load image;

img = imread("Batman.png");

% Display original image
figure;
imshow(img);
title('Original Image');

% Convert to grayscale
grayscale_img = rgb2gray(img);

% Display grayscale image
figure;
imshow(grayscale_img);
title('Grayscale Image');

% Create negative image
output = 255 - grayscale_img;

% Display negative image
figure;
imshow(uint8(output));
title('Negative Image');

% Save images
imwrite(grayscale_img, "Batman_grayscale.png");
imwrite(uint8(output), "Batman_negative.png");
