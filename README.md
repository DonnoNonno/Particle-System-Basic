[Link to Git-Hub](https://github.com/DonnoNonno/Particle-System-Basic)

[Link to Website](https://donnononno.github.io/Particle-System-Basic/)
 

# Introduction

In this document we will talk about particles used in video games, how it works and how to integrate it in your 2D project.
This whole website will be focused on the c++ language and will be using Visual Studio 2020 and SDL 2.

We will explain everything about particle systems and will help you with some exercises to implement it yourself.

One important thing that  you should know is that this is probably not the best method to create a particle system, sure there will be better ones at this and professionals that can do it better than I.

Then, Let’s get Started.

![Image Alt Text](https://github.com/DonnoNonno/Particle-System-Basic/blob/master/Images/pink_sparkles_finished.gif)

## What is a particle system and why do we use it in video games?

A particle system is a computer graphics technique used to simulate the behavior and appearance of a large number of small particles, such as dust, smoke, fire, water droplets, or other types of particles in a virtual environment. Each particle in a particle system is typically represented as a small point or sprite that has various attributes, such as position, velocity, size, color, and lifetime.
Particle systems are commonly used in video games, computer simulations, visual effects in movies and animations, and other interactive applications to create realistic or stylized visual effects that can enhance the overall visual appeal and immersion of a virtual scene.

# Parts:

## Emitters: 

Emitters are the sources from which particles are spawned or emitted. They define the position, direction, and behavior of particles as they are created and released into the scene. Emitters can have various shapes, sizes, and properties, and they control how particles are generated and distributed in the simulated environment.
Particle systems can be designed to emit particles in various ways, such as from a point, a line, a shape, or even from other particles. Particle behavior can also be controlled using rules or forces, such as gravity, wind, and attraction/repulsion forces, to simulate realistic or stylized particle motion.

![Image Alt Text](https://github.com/DonnoNonno/Particle-System-Basic/blob/master/Images/DOOM-Eternal-Particles.png)

## Particles: 

Particles are the small objects that are created and managed by a particle system. They are rendered as images or shapes and represent the individual elements that make up the visual effect. Particles can have properties such as position, velocity, size, color, and lifespan, which are manipulated over time to create the desired visual effect.

![Image Alt Text](https://github.com/DonnoNonno/Particle-System-Basic/blob/master/Images/Captura1.PNG)

## Parameters: 

Parameters are the settings and attributes that control the behavior and appearance of particles in a particle system. They can include settings for particle emission rate, particle velocity, particle size, particle color, and other properties that determine how particles behave and look in the simulated environment.

## Module: 
A module is a self-contained unit of code that performs a specific function within a particle system. It can be a collection of functions, classes, or other code components that are organized together to achieve a specific purpose, such as particle emission, particle updating, or particle rendering.

## Class: 

A class is a blueprint or template for creating objects that share common properties and behaviors. In the context of a particle system, classes can be used to define the properties and behaviors of particles, emitters, and other components of the particle system. Classes encapsulate the logic and data related to specific entities within the particle system and provide a way to organize and manage their functionality.

## Pools: 

Pools are collections or caches of reusable objects that are used to efficiently manage the creation and destruction of particles in a particle system. Pools can be used to recycle particles that are no longer needed, instead of creating new particles from scratch, which can help improve performance and reduce memory usage.

## Rendering Techniques:

Particle systems can be rendered using different techniques, such as point sprites, billboards, or textured quads, which are aligned to face the camera to give the illusion of three-dimensional particles. These particles can be rendered using various shading, blending, and texturing techniques to achieve the desired visual appearance.

![Image Alt Text](https://github.com/DonnoNonno/Particle-System-Basic/blob/master/Images/preview.gif)

## Advanced Techniques: 

Particle systems can also be combined with other computer graphics techniques, such as physics simulations, procedural generation, and artificial intelligence, to create more complex and interactive visual effects.
How is it structured?

![Image Alt Text](https://github.com/DonnoNonno/Particle-System-Basic/blob/master/Images/Particle_sys_fire.jpg)


