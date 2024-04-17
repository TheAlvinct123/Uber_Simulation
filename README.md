# Project Overview
The purpose of this project was to simulate a ride scheduling app similar to that of Uber
or Lyft. The project uses drones as the vehicles for the rides and robots as the riders. Throughout
the simulation the drones’ batteries drain and they have to fly to one of the five stations to
recharge them. The simulation can be viewed with a 3d visualization and trips can be scheduled
through a html interface.

## Running the Simulation
To run the simulation first clone the repository. 
Next make sure to install the Makefile extention. 
Once in the project directory build the project with: 
                make -j
Then start the project server with:
        ./build/bin/transit_service <port> apps/transit_service/web/
Where <port> is the port number that the server will run on, we used port 8081. After starting
the simulation, open a web browser and navigate to http://127.0.0.1:<port> where <port> is
replaced with the port number you used when starting the simulation. This is the main viewing
interface for the simulation. In order to schedule trips open up a second tab and navigate to
http://127.0.0.1:<port>/schedule.html.

### Simulation Overview
Schedule
On the scheduling page found at http://127.0.0.1:<port>/schedule.html you can schedule
trips for robots as well as add helicopters and UFOs to the simulation.
To schedule a trip for a robot first enter a name for the robot in the box at the top of the page.
Then select a routing search algorithm from the drop down menu below the name box. This
algorithm will determine what route the drone will carry the robot on. Next click on the map
where you would like the robot to start from and click again for where you would like it to go.
After this step there should be two circles on the map showing the start and end location you
selected. Finally click the “Schedule Trip” button below the map. The trip you just scheduled
should appear in the “Trips” sidebar on the right. Now go to the simulation view and change the
view in the upper right corner to be for the entity you just created.
To add another helicopter or UFO scroll to the bottom of the page. There you will find
the buttons “Add Helicopter” and “Add UFO”. Click on the button you would like then go to the
simulation view and change the view in the upper right corner to see the helicopter or UFO you
just added.
Simulation View
On the simulation page found at http://127.0.0.1:<port> you can view the movement of
the drones, robots, cars, and UFOs. In the upper right corner there is a dropdown menu that
allows you to select which entity the camera will follow. Below that there is a slider that controls
the speed of the simulation. Sliding it further to the right will speed up all motion and drain the
drone's battery faster. The last control in the upper right is a check box that toggles whether the
possible routes are visible. These routes are what the drones will follow while carrying a robot.
The left sidebar displays the battery level of each drone with a little indicator. As the drone’s
battery drains the battery indicator empties and changes color from green to orange to red.