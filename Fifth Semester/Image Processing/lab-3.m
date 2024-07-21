clear all;
close all;
clc;

a=imread('Batman.png');
subplot(2,2,1);
imshow(a);
title 'Original Image';
b=im2double(a);

s=(1*log(1+b))*256;
s1 = uint8(s);
subplot(2,2,2);
imshow(s1);
title 'c=1';

sp = (10*log(1+b))*256;
s2 = uint8(sp);
subplot(2,2,2);
imshow(s2);
title 'c=10';
clear all;
close all;
clc;

a=imread('Batman.png');
subplot(2,2,1);
imshow(a);
title 'Original Image';
b=im2double(a);

s=(1*log(1+b))*256;
s1 = uint8(s);
subplot(2,2,2);
imshow(s1);
title 'c=1';

sp = (10*log(1+b))*256;
s2 = uint8(sp);
subplot(2,2,3);
imshow(s2);
title 'c=10';

sp2 = (200*log(1+b))*256;
s3 = uint8(sp2);
subplot(2,2,4);
imshow(s3);
title 'c=200';
