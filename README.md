-----RELIEF FUND SYSTEM-------

A C++ console program that decides what kind of relief to send to disaster-affected areas. For each aid request it calculates
a need score, picks a relief action, checks whether enough resources are left, and downgrades the action if they are not.

---HOW TO RUN IT---

1.Choose a starting mode: "sufficient" or "insufficient".\
2.Type "request" to enter a new request (or "stop" to finish).\
3.Enter damage level, families affected (10–200), access route, flood warning, medical need, and previous aid.\

--STARTING RESOURCES--
|Resource      |	Sufficient	|Insufficient |
|--------------|--------------|-------------|
|Trucks        |    	5       |    	1       |
|Supply packs  |	  120       |    	10      |
|Helicopters	 |      2	      |      1      |
|Boats         |     	3	      |     0       |
|Ambulances	   |      4       |     1       |
|Police        |     	3       |    	1       |

Any input other than sufficient starts the insufficient mode.

--NEED SCORE CALCULATION--

needScore = (2*damagelevel) + familiesaffected + (2*damagedroute) + (2*floodwarring) + medicalneed - previousAid
