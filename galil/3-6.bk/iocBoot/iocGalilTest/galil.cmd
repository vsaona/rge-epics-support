## uncomment to see every command sent to galil
# epicsEnvSet("GALIL_DEBUG_FILE", "galil_debug.txt")

# Load motor records for real and coordinate system (CS) motors
dbLoadTemplate("$(TOP)/GalilTestApp/Db/galil_motors-v6-10up.substitutions")

# Load DMC controller features (eg.  Limit switch type, home switch type, output compare, message consoles)
dbLoadTemplate("$(TOP)/GalilTestApp/Db/galil_dmc_ctrl.substitutions")

# Load extra features for real axis/motors (eg. Motor type, encoder type)
dbLoadTemplate("$(TOP)/GalilTestApp/Db/galil_motor_extras.substitutions")

# Load user defined functions
dbLoadTemplate("$(TOP)/GalilTestApp/Db/galil_userdef_records.substitutions")

# Load user defined array support
dbLoadTemplate("$(TOP)/GalilTestApp/Db/galil_user_array.substitutions")

# Load profiles
dbLoadTemplate("$(TOP)/GalilTestApp/Db/galil_profileMoveController.substitutions")
dbLoadTemplate("$(TOP)/GalilTestApp/Db/galil_profileMoveAxis.substitutions")

# Create a Galil controller
GalilCreateController("Galil", "192.168.42.2", 8)

# Create the axis
GalilCreateAxis("Galil","A",1,"",1)

# Start the controller
GalilStartController("Galil", "", 1, 0)

# Create trajectory profiles
GalilCreateProfile("Galil", 2000)
