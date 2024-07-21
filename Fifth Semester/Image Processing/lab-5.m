clear all;
close all;
clc;

pkg load image;

i=imread("Batman.png");
b0=double(bitget(i,1));
b1=double(bitget(i,2));
b2=double(bitget(i,3));
b3=double(bitget(i,4));
b4=double(bitget(i,5));
b5=double(bitget(i,6));
b6=double(bitget(i,7));
b7=double(bitget(i,8));
subplot(3,3,1);imshow(i);title("Original Image");
subplot(3,3,2);subimage(b0);title("Bit Plane 0");
subplot(3,3,3);subimage(b1);title("Bit Plane 1");
subplot(3,3,4);subimage(b2);title("Bit Plane 2");
subplot(3,3,5);subimage(b3);title("Bit Plane 3");
subplot(3,3,6);subimage(b4);title("Bit Plane 4");
subplot(3,3,7);subimage(b5);title("Bit Plane 5");
subplot(3,3,8);subimage(b6);title("Bit Plane 6");
subplot(3,3,9);subimage(b7);title("Bit Plane 7");
