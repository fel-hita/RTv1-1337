# RTv1-1337-
raytracer using sdl library.

<p align="center"> Project Final Mark : </p>
<p align="center"><img width="350" height="300" src="https://i.imgur.com/MhLuPX1.png"> </p>

## Screenshots

![img0][0]
![img1][1]
![img2][2]
![img3][3]
![img4][4]

## Configuration file

![img5][5]

Scenes are located in (cloned-folder-name)/data/scenes

Each configuration file must have at least two components to render the scene : a light and a camera components.

All inputs are floating numbers.

## Camera format : 
0.0 0.0 0.0 (initial position vector x y z)
0.0 0.0 -1.0 (direction or camera fixed look position vector)
60.0 (field of view angle in degrees)

## Light format : 
0.0 100.0 -10 ( <- x y z position vector) 1.0 1.0 1.0 (r g b light color clamped between 0-1.0)

## Shapes format : 

plane (shape name)

0 -2.0 -1000.0 (x y z original position in space vector)

0.0 0.0 0.0 (x y z translation vector)

0.0 0.0 0.0 (x y z rotation vector in degrees)

0.0 1.0 0.0 (shape special property value [read shapes property list])

1.0 0.0 1.0 (object color ![#f03c15](https://placehold.it/15/f03c15/000000?text=+) r ![#c5f015](https://placehold.it/15/c5f015/000000?text=+) g 
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) b clamped 0-1)

1.0 1.0 1.0 (specular r g b color)

60.0 (specular brightness)

0.0 0.0 1.0 (reflection - refraction - texture [0-1 except for sphere has earth texture for a value of 2])


## Shapes list (correct names used for config file) :

(these are the shapes for the mandatory part of the project RTv1)
### sphere - cone - plane - cylindre

(our own added shapes)
### box - cube - disk - torus 

## Shapes property list :

Sphere, Cylindre, Disk, Cube & Torus -> Radius

Cone (infinite cone) -> Opening angle

Plane -> vector surface normal

Box -> No property / Skip line input.


## Raytracer key inputs :

Ctrl + Right mouse click on object to select it, then either delete it from the scene or add a new shape of the same type by clickin on the corresponding name on the RT hud.

Arrow keys : UP, DOWN / translation -Z, +Z. | LEFT, RIGHT / translation -X, +X.

AWSD[ZQSD on azerty] : A, D / rotation -Y, +Y.  |  W, S   / rotation +X, -X.

ZX : Z, X / translation -Y, +Y.



[0]: https://i.imgur.com/vxfvcha.png "first"
[1]: https://i.imgur.com/DvmYPiM.png "second"
[2]: https://i.imgur.com/6Vz7f39.png "third"
[3]: https://i.imgur.com/uldrOnd.png "fourth"
[4]: https://i.imgur.com/CtPBVyj.png "fifth"
[5]: https://i.stack.imgur.com/9KgUe.png "sixth"
