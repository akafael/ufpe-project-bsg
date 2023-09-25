%% BSG data inport script

%% INSTRUCTIONS
% To run the model, there are 5 steps that must be followed:
%
% 1) Make sure to create a .csv file located in the same directory as this
% script with the correct structure;
%
% 2)Run this script in order to define the variables in the Workspace;
%
% 3)Open the Simulink model and in MODELING -> Model Settings -> Data
% Inport/Export -> Input make sure that 'dataStructure' is 
% defined as the input;
%
% 4)Make sure to change the dimensions of all input blocks to match the
% ones defined as '1'  in this script.
%
% 5)Run the model.

%% Data Inport

%reads data from .csv file located in the same directory as this script;
data = readmatrix('data.csv');

%defines the time period in wich the simulation will take place;
time = (0:1:10)';

%defines the data structure called 'dataStructure' that will be
%reffereneced in the model
dataStructure.time = time;

%the number indicated in .signals() represents the input block index to
%wich the collumn of the .csv file is linked 
dataStructure.signals(1).values = data(:, 1); 
dataStructure.signals(2).values = data(:, 2); 
dataStructure.signals(3).values = data(:, 3); 
dataStructure.signals(4).values = data(:, 4);
dataStructure.signals(5).values = data(:, 5);

%specifies the dimension that must be refferenced in each input block in the
%model
dataStructure.signals(1).dimensions = 1; 
dataStructure.signals(2).dimensions = 1; 
dataStructure.signals(3).dimensions = 1; 
dataStructure.signals(4).dimensions = 1;
dataStructure.signals(5).dimensions = 1; 
