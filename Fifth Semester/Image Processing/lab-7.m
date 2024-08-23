clear all;
close all;
clc;

pkg load image;

i=imread("Batman.png");
i = i(:,:,1); subplot(2,2,1); imshow(i); title("Original Image");
a = [0.001 0.001 0.001 0.001 0.001 0.001 0.001 0.001 0.001 ];
R = conv2(a,i);
 subplot(2,2,2); imshow(R); title("Filtered Image");
 b = [0.005 0.005 0.005 0.005 0.005 0.005 0.005 0.005 0.005 ];
R = conv2(b,i);
 subplot(2,2,3); imshow(R); title("Filtered Image 2");
