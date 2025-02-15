# [G. The Bifrost Challenge](https://codeforces.com/gym/588606/problem/G)

---
Asgard, the gleaming realm of the gods, is in turmoil. Malekith, the dark elf, has tampered with the Bifrost, the cosmic bridge system that connects the nine realms. Each segment of the bridge now radiates with unpredictable energy, and the once seamless travel has become perilous. Thor, wielding the mighty Mjolnir, must restore order and ensure safe passage across the realms.The Bifrost is a sprawling network, with N key junctions interconnected by bi-directional energy channels. Each channel carries an intensity value representing the strength of the cosmic energy flowing through it. The network is in the form of a tree. Malekith's corruption has made it vital for Thor to determine the maximum energy intensity encountered when traveling between any two junctions. Thor can traverse each channel on the path between the two junctions only once.Thor receives Q calls for aid, each asking him to analyze the cosmic pathways between two specific junctions and identify the most intense segment along the way. Though the task is daunting, Mjolnir's power allows Thor to analyze the structure quickly.Your mission is to assist Thor in completing this vital task and save the realms !!

### Input
InputThe first line contains two integers, N (the number of key junctions) and Q (the number of aid calls Thor receives). (2≤N≤105,1≤Q≤105)The next N−1 lines describe the energy channels. Each line contains three integers, A,B,W, indicating an energy channel between junctions A and B with an intensity of W. (1≤A,B≤N,1≤W≤106)The following Q lines each contain two integers, U and V (U≠V) representing the junctions Thor needs to analyze.

### Output
OutputFor each aid call, output a single integer: the maximum energy intensity along the cosmic pathway between U and V.
Note  Thor investigates the pathways as follows:   On the pathway from 2 to 4, the maximum intensity encountered is 5.  On the pathway from 2 to 5, the maximum intensity encountered is 4.  On the pathway from 1 to 4, the maximum intensity encountered is 5.
