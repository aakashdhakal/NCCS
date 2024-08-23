clear all;
close all;
clc;

pkg load image;

i=imread("Batman.png");
subplot(4,2,1);imshow(i);title("Original Image");
g = rgb2gray(i);
subplot(4,2,5);imshow(i);title("Gray Image");
j = imadjust(g,[0.3,0.7],[]);
subplot(4,2,3);imshow(i);title("Enhanced Image");
d = imadjust(i,[0.2 0.3 0; 0.6 0.7 1],[]);
subplot(4,2,4);imshow(d);title("Enhanced Image 2");

subplot(4,2,7);imhist(g);title("Histogram of gray image");
m= histeq(g);
subplot(4,2,6);imshow(m);title("Equalized Image");
subplot(4,2,8);imhist(m);title("Histogram of equalized image");


