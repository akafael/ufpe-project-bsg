% MATLAB code

t = 0:1:50;
y = t.^2;

% Start the Figure
figure;

mkdir('matlab_frames');

% Creates and saves images in a loop
for i = 1:length(t)
    plot(t(1:i), y(1:i));
    title('y = t^2');
    xlabel('time');
    ylabel('response');
    drawnow; % Updates the figure
    frame = getframe(gcf); % Captures the frame
    im = frame2im(frame); % Converts to image
    filename = ['matlab_frames/frame_' num2str(i) '.png']; % Saves in the correct folder'
    imwrite(im, filename, 'png');
end
