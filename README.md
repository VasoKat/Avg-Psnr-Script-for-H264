# Avg-Psnr-Script-for-H.264
H.264 is a well-known video compression standard for high-definition digital video. 
When running rtp_loss.cpp (inside JM/rtp_loss), different packets are lost. Since the packet losses 
are random, it is not enough to run the simulation once. We have to repeat the process several times and get
the average PSNR (Peak signal-to-noise ratio). This script, implemented in c++, repeats the video 
transmission simulation 100 times and calculates the average PSNR for packet loss rate 5%. The
script is inside the catalog JM/bin in H.264. 