Defined a function named "MyCommand" to display the message "Hello <Name> in the world of AutoCAD" when
the user enters the command in the AutoCAD command line.

steps:

**Initialization**:
Unlocks the application and registers it as MDI (Multiple Document Interface) aware.
Prints a message to the AutoCAD command line, indicating that the application has been loaded.
Registers a new modal command named "MYCOMMAND" in the "MyGroup" group, associating it with the MyCommand function in the CExercise3App class.

**Custom Command (MyCommand):**
Defines the behavior of the custom command "MYCOMMAND" to print the message "Hello to the world of AutoCAD!!!" to the AutoCAD command line.

**Unload:**
Prints a message to the AutoCAD command line, indicating that the application is being unloaded.
