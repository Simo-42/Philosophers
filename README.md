# Philosophers

This project is about learning the basics of threading a process.\
You will see how to create threads and you will discover mutexes.
![236896019-3d1799bb-e9b6-4b08-ba31-5ec05750267b](https://github.com/Yonix49/Philosophers/assets/111706060/f43ef386-d3bc-4f58-9863-1c51bc218477)
The problem was designed to illustrate the challenges of avoiding deadlock, a system state in which no progress is possible. \
To see that a proper solution to this problem is not obvious, consider a proposal in which each philosopher is instructed to behave as follows:

* think unless the left fork is available; when it is, pick it up;
* think unless the right fork is available; when it is, pick it up;
* when both forks are held, eat for a fixed amount of time;
* put the left fork down;
* put the right fork down;
* repeat from the beginning.
* However, they each will think for an undetermined amount of time and may end up holding a left fork thinking, staring at the right side of the plate, unable to eat because there is no right fork, until they starve.
* Here a demo of the project bellow :

  ![Demo of the project](assets/Philosophers.gif)

