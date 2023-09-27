import random

# vehicle.velocity
vehicleVelocityMINIMUM = 0
vehicleVelocityMAXIMUM = 200

# vehicle.angleAccPedal
vehicleAngleAccPedalMINIMUM = 0
vehicleAngleAccPedalMAXIMUM = 180

# vehicle.angleBrakePedal
vehicleAngleBrakePedalMINIMUM = 0
vehicleAngleBrakePedalMAXIMUM = 90

# vehicle.requestCarStart
vehicleRequestCarStartMINIMUM = 0
vehicleRequestCarStartMAXIMUM = 1

# battery.voltage
batteryVoltageMINIMUM = 0
batteryVoltageMAXIMUM = 48

# battery.current
batteryCurrentMINIMUM = -350
batteryCurrentMAXIMUM = 350

# bsg.currentMode
bsgCurrentModeMINIMUM = 0
bsgCurrentModeMAXIMUM = 3

# bsg.rpm
bsgRpmMINIMUM = 0
bsgRpmMAXIMUM = 1800

# bsg.voltage
bsgVoltageMINIMUM = 0
bsgVoltageMAXIMUM = 48

# bsg.current
bsgCurrentMINIMUM = 0
bsgCurrentMAXIMUM = 300

# engine.rpm
engineRPMMINIMUM = 0
engineRPMMAXIMUM = 8000

# engine.velocity
engineVelocityMINIMUM = 0
engineVelocityMAXIMUM = 200

# engine.gear 
engineGearMINIMUM = -1
engineGearMAXIMUM = 6

randomVehicleVelocity = 0
randomVehicleAngleAccPedal = 0
randomVehicleAngleBrakePedal = 0
randomVehicleRequestCarStart = 0
randomBatteryVoltage = 0
randomBatteryCurrent = 0
randomBsgCurrentMode = 0
randomBsgRpm = 0
randomBsgVoltage = 0
randomBsgCurrent = 0
randomEngineRPM = 0
randomEngineVelocity = 0
randomEngineGear = 0





file_name = 'w.csv'

title =   ['vehicle.velocity', 
           'vehicle.angleAccPedal', 
           'vehicle.angleBrakePedal', 
           'vehicle.requestCarStart', 
           'battery.voltage', 
           'battery.current', 
           'bsg.currentMode', 
           'bsg.rpm', 
           'bsg.voltage', 
           'bsg.current', 
           'engine.rpm', 
           'engine.velocity', 
           'engine.gear ']

data = []

for _ in range(10):

          # Generating random numbers from defined ranges
          randomVehicleVelocity = random.randint(vehicleVelocityMINIMUM, vehicleVelocityMAXIMUM)
          randomVehicleAngleAccPedal = random.randint(vehicleAngleAccPedalMINIMUM, vehicleAngleAccPedalMAXIMUM)
          randomVehicleAngleBrakePedal = random.randint(vehicleAngleBrakePedalMINIMUM, vehicleAngleBrakePedalMAXIMUM)
          randomVehicleRequestCarStart = random.randint(vehicleRequestCarStartMINIMUM, vehicleRequestCarStartMAXIMUM)
          randomBatteryVoltage = random.randint(batteryVoltageMINIMUM, batteryVoltageMAXIMUM)
          randomBatteryCurrent = random.randint(batteryCurrentMINIMUM, batteryCurrentMAXIMUM)
          randomBsgCurrentMode = random.randint(bsgCurrentModeMINIMUM, bsgCurrentModeMAXIMUM)
          randomBsgRpm = random.randint(bsgRpmMINIMUM, bsgRpmMAXIMUM)
          randomBsgVoltage = random.randint(bsgVoltageMINIMUM, bsgVoltageMAXIMUM)
          randomBsgCurrent = random.randint(bsgCurrentMINIMUM, bsgCurrentMAXIMUM)
          randomEngineRPM = random.randint(engineRPMMINIMUM, engineRPMMAXIMUM)
          randomEngineVelocity = random.randint(engineVelocityMINIMUM, engineVelocityMAXIMUM)
          randomEngineGear = random.randint(engineGearMINIMUM, engineGearMAXIMUM)

          vehicleVelocity = randomVehicleVelocity
          vehicleAngleAccPedal = randomVehicleAngleAccPedal
          vehicleAngleBrakePedal = randomVehicleAngleBrakePedal
          vehicleRequestCarStart = randomVehicleRequestCarStart
          batteryVoltage = randomBatteryVoltage
          batteryCurrent = randomBatteryCurrent
          bsgCurrentMode = randomBsgCurrentMode 
          bsgRpm = randomBsgRpm
          bsgVoltage = randomBsgVoltage
          bsgCurrent = randomBsgCurrent 
          engineRpm = randomEngineRPM 
          engineVelocity = randomEngineVelocity
          engineGear = randomEngineGear
          
          data.append([vehicleVelocity, 
                         vehicleAngleAccPedal, 
                         vehicleAngleBrakePedal, 
                         vehicleRequestCarStart , 
                         batteryVoltage, 
                         batteryCurrent,
                         bsgCurrentMode,
                         bsgRpm,
                         bsgVoltage,
                         bsgCurrent,
                         engineRpm,
                         engineVelocity,
                          engineGear])
           
    #Writing CSV file 
with open(file_name, 'w', newline='') as file_csv:
    write_csv = csv.writer(file_csv)
    
    # Writing Title
    write_csv.writerow(title)
    
    # Writing data
    write_csv.writerows(data)

print(f'Data has been generated and saved in {file_name}')
print(data)