⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮  
⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰  
∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷  
     wireframe model landscape in progress  
∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷  
⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰⋰  
⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮⋮  
  
     👩🏻‍🎨 👩🏻‍💻 🕸 🏸 🥅 🚧 🏗  


![Alt text](fdf.jpeg "not mine")

## STAPPENPLAN:  
- miniLibX clonen en werkend krijgen  
- input parsen  
- miniLibX onderzoeken (sparksessie?)  
- https://www.khanacademy.org/computing/computer-programming/programming-games-visualizations/programming-3d-shapes/a/creating-3d-shapes  
- describing 3D shapes  
- drawing 3D shapes  
- rotating 3D shapes  
- https://github.com/VBrazhnik/FdF/wiki 
- https://git.42l.fr/Fabien/fdf 
- isometric transformations uitzoeken  
- sin tan cos uitzoeken  
- drawing a line uitzoeken 
- raster tekenen  
- data punten draaien  
- code slayen  
  
### Opdracht:  
- Your program has to display the image in a window.  
- The management of your window must remain smooth  
(changing to another window, minimizing, and so forth).  
- Pressing ESC must close the window and quit the program in a clean way.  
- Clicking on the cross on the window’s frame must close the window  
and quit the program in a clean way.  
  
  
  
- struct met x, y, z  
- voor elk data punt een struct aanmaken  
- elk struct in een array zetten  
- OF: map lezen als string, splitten op spatie  
- x = hoeveelste "woord" per lijn  
- y = hoeveelste rij = \n tellen  
- z = inhoud van nummer  
  


## TO DO:  
- make edit_data_points universal for every map (space between data points)  
- centering grid in middle of image  
- 


# Facts  
Isometric projection is a method for visually representing three-dimensional  
objects in two dimensions in technical and engineering drawings. It is an   
axonometric projection in which the three coordinate axes appear equally   
foreshortened and the angle between any two of them is 120 degrees.  
The term "isometric" comes from the Greek for "equal measure",   
reflecting that the scale along each axis of the projection is the same.  
True isometric projection uses a 30° angle (0.523599 rad).  

Representative Scale (RF) = iso length / true length  
RF = cos(45)/cos(30)  
So, iso lengths = 0.82 x true lengths  

