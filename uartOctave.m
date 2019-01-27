 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % This program is intended for reading ADC
 % values from external source over UART. 
 % Author: Golam Gause Jaman
 % email: jamagola@isu.edu
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 clear all;
 clc;
 
 pkg load instrument-control
 obj = serial('COM3');
 set(obj, 'baudrate',9600);
 set(obj, 'timeout',20); % 2 seconds time out
 
 limit=60000;
 dt=0.1; %Interval
 L=4; %Length
 ul=1023; %Max reading
 
 ex=zeros(1,L);
 for e=0:L-1
   ex(L-e)=10^e;
 end
 
 % Display info.
 obj
 fopen(obj);
 ws = zeros(1,limit+1);
 % UART(starts receiving data)
 for i=2:limit
   out=srl_read(obj,4);
   ws(i)=(double(out)-48)*ex';
   
   % Plot
   plot([i-1,i],[ws(i-1),ws(i)],'r-');
   grid on;
   hold on;
   if i<=51  %x window
    axis([1,51,0,ul]);
  else
    axis([i-50,i,0,ul]);
  end
  xlabel('Sample');
  ylabel('Amplitude');
  pause(dt*0.5);
 end
 
 fclose(obj);