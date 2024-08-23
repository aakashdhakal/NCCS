clear all;%clear all variables
close all;%close all figures
clc; %clear command window
%import image package
pkg load image;
I=im2double(imread('Batman.png'));
f1=fft(I);
f2=fftshift(f1);

subplot(2,2,1); imshow(abs(f1)); title('Frequency Spectrum');
subplot(2,2,2); imshow(abs(f2)); title('Centered Spectrum');
f3=log(1+abs(f2));
subplot(2,2,3); imshow(f3); title('log(1+abs(f2))');
I=fft2(f1);
I1=real(I);
subplot(2,2,4); imshow(I1); title('2-D FFT');

