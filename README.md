1. Build

$ ./xbuild.sh 

2. Run

$ ./build/sim_h3_mining 15 3 120


3. Check the log file 'SH3M_Log.txt'

Example log:

60848577796, 0, Log started. Output to file='SH3M_Log.txt'
60848577846, 0, Timestamp unit [us]
60848577984, 0, Truck0 [Mining] till time=109 (for 109)
60848577998, 0, Truck1 [Mining] till time=268 (for 268)
60848578014, 0, Truck2 [Mining] till time=77 (for 77)
60848578026, 0, Truck3 [Mining] till time=216 (for 216)
60848578038, 0, Truck4 [Mining] till time=209 (for 209)
60848578049, 0, Truck5 [Mining] till time=244 (for 244)
60848578060, 0, Truck6 [Mining] till time=255 (for 255)
60848578071, 0, Truck7 [Mining] till time=130 (for 130)
60848578090, 0, Truck8 [Mining] till time=103 (for 103)
60848578103, 0, Truck9 [Mining] till time=170 (for 170)
60848578114, 0, Truck10 [Mining] till time=154 (for 154)
60848578125, 0, Truck11 [Mining] till time=128 (for 128)
60848578136, 0, Truck12 [Mining] till time=110 (for 110)
60848578147, 0, Truck13 [Mining] till time=171 (for 171)
60848578157, 0, Truck14 [Mining] till time=177 (for 177)
60848578187, 0, Sim: time now=0 < end=120
60848578194, 0, Sim: Truck2 nearest event in state [Mining] time=77
60848578202, 0, Sim: time now=0 < end=120
60848578205, 0, Sim: Time step now=0 new_time=77
60848578224, 77, Truck2 mined for 1.3 hours.
60848578226, 77, Truck2 state [Mining] transition to [TravelingToUnload]
60848578229, 77, Truck2 [TravelingToUnload] till time=107 (for 30)
60848578231, 77, Sim: Truck2 executed event in [TravelingToUnload] state
60848578235, 77, Sim: Truck8 nearest event in state [Mining] time=103
60848578238, 77, Sim: time now=77 < end=120
60848578240, 77, Sim: Time step now=77 new_time=103
60848578243, 103, Truck8 mined for 1.7 hours.
60848578245, 103, Truck8 state [Mining] transition to [TravelingToUnload]
60848578247, 103, Truck8 [TravelingToUnload] till time=133 (for 30)
60848578248, 103, Sim: Truck8 executed event in [TravelingToUnload] state
60848578252, 103, Sim: Truck2 nearest event in state [TravelingToUnload] time=107
60848578255, 103, Sim: time now=103 < end=120
60848578257, 103, Sim: Time step now=103 new_time=107
60848578258, 107, Truck2 traveling to unload station.
60848578260, 107, Truck2 state [TravelingToUnload] transition to [WaitingInQueue]
60848578262, 107, Truck2 [WaitingInQueue] till time=107 (for 0)
60848578264, 107, Sim: Truck2 executed event in [WaitingInQueue] state
60848578267, 107, Sim: Station0 queue add Truck2, nearest unload start time=0
60848578271, 107, Sim: To Station0 not occupied QLen=0 ADD Truck2 [WaitingInQueue] unload finish time=112
60848578273, 107, Truck2 waiting in queue to unload.
60848578275, 107, Truck2 state [WaitingInQueue] transition to [Unloading]
60848578277, 107, Truck2 [Unloading] till time=112 (for 5)
60848578281, 107, Sim: Truck0 nearest event in state [Mining] time=109
60848578284, 107, Sim: time now=107 < end=120
60848578287, 107, Sim: Time step now=107 new_time=109
60848578289, 109, Truck0 mined for 1.8 hours.
60848578290, 109, Truck0 state [Mining] transition to [TravelingToUnload]
60848578293, 109, Truck0 [TravelingToUnload] till time=139 (for 30)
60848578294, 109, Sim: Truck0 executed event in [TravelingToUnload] state
60848578298, 109, Sim: Truck12 nearest event in state [Mining] time=110
60848578301, 109, Sim: time now=109 < end=120
60848578303, 109, Sim: Time step now=109 new_time=110
60848578305, 110, Truck12 mined for 1.8 hours.
60848578306, 110, Truck12 state [Mining] transition to [TravelingToUnload]
60848578308, 110, Truck12 [TravelingToUnload] till time=140 (for 30)
60848578310, 110, Sim: Truck12 executed event in [TravelingToUnload] state
60848578313, 110, Sim: Truck2 nearest event in state [Unloading] time=112
60848578317, 110, Sim: Station0 Unloaded Truck2 state [Unloading] time=112
60848578319, 112, Sim: time now=112 < end=120
60848578321, 112, Sim: Time step now=112 new_time=112
60848578323, 112, Truck2 waiting in queue and unloading for 5.
60848578325, 112, Truck2 state [Unloading] transition to [TravelingToMine]
60848578327, 112, Truck2 [TravelingToMine] till time=142 (for 30)
60848578329, 112, Sim: Truck2 executed event in [TravelingToMine] state
60848578332, 112, Sim: Truck11 nearest event in state [Mining] time=128
60848578414, 112, Sim: time now=112 < end=120
60848578421, 112, Sim: Time step now=112 new_time=128
60848578428, 128, Truck11 mined for 2.1 hours.
60848578433, 128, Truck11 state [Mining] transition to [TravelingToUnload]
60848578439, 128, Truck11 [TravelingToUnload] till time=158 (for 30)
60848578444, 128, Sim: Truck11 executed event in [TravelingToUnload] state
60848578449, 128, Sim: Truck7 nearest event in state [Mining] time=130
60848578453, 128, Simulation done after 120 min
60848578455, 128, ========================= STATISTICS ========================
60848578457, 128, Simulation
60848578459, 128, Total Unloads: 0
60848578462, 128, Total Mine Time: 0 minutes
60848578466, 128, Total Wait in Unload Queue: 0 minutes
60848578468, 128, Total Operation Cycles: 0
60848578470, 128, Truck0
60848578474, 128, Total Operation Cycles: 0
60848578478, 128, Total Wait Time in Unload Queues: 0 minutes
60848578484, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578486, 128, Total Travel Time: 0 minutes
60848578488, 128, Total Mining Time: 0 minutes
60848578491, 128, Average Mining Time: 0.00 minutes
60848578493, 128, Mining to Simulation Time Ratio: 0.00%
60848578496, 128, Truck1
60848578498, 128, Total Operation Cycles: 0
60848578500, 128, Total Wait Time in Unload Queues: 0 minutes
60848578502, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578506, 128, Total Travel Time: 0 minutes
60848578510, 128, Total Mining Time: 0 minutes
60848578513, 128, Average Mining Time: 0.00 minutes
60848578518, 128, Mining to Simulation Time Ratio: 0.00%
60848578520, 128, Truck2
60848578522, 128, Total Operation Cycles: 0
60848578525, 128, Total Wait Time in Unload Queues: 0 minutes
60848578530, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578534, 128, Total Travel Time: 0 minutes
60848578536, 128, Total Mining Time: 0 minutes
60848578541, 128, Average Mining Time: 0.00 minutes
60848578546, 128, Mining to Simulation Time Ratio: 0.00%
60848578550, 128, Truck3
60848578554, 128, Total Operation Cycles: 0
60848578558, 128, Total Wait Time in Unload Queues: 0 minutes
60848578563, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578567, 128, Total Travel Time: 0 minutes
60848578571, 128, Total Mining Time: 0 minutes
60848578576, 128, Average Mining Time: 0.00 minutes
60848578581, 128, Mining to Simulation Time Ratio: 0.00%
60848578585, 128, Truck4
60848578587, 128, Total Operation Cycles: 0
60848578589, 128, Total Wait Time in Unload Queues: 0 minutes
60848578593, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578597, 128, Total Travel Time: 0 minutes
60848578601, 128, Total Mining Time: 0 minutes
60848578604, 128, Average Mining Time: 0.00 minutes
60848578609, 128, Mining to Simulation Time Ratio: 0.00%
60848578613, 128, Truck5
60848578617, 128, Total Operation Cycles: 0
60848578621, 128, Total Wait Time in Unload Queues: 0 minutes
60848578626, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578628, 128, Total Travel Time: 0 minutes
60848578630, 128, Total Mining Time: 0 minutes
60848578633, 128, Average Mining Time: 0.00 minutes
60848578635, 128, Mining to Simulation Time Ratio: 0.00%
60848578636, 128, Truck6
60848578637, 128, Total Operation Cycles: 0
60848578638, 128, Total Wait Time in Unload Queues: 0 minutes
60848578640, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578641, 128, Total Travel Time: 0 minutes
60848578643, 128, Total Mining Time: 0 minutes
60848578644, 128, Average Mining Time: 0.00 minutes
60848578646, 128, Mining to Simulation Time Ratio: 0.00%
60848578647, 128, Truck7
60848578648, 128, Total Operation Cycles: 0
60848578650, 128, Total Wait Time in Unload Queues: 0 minutes
60848578651, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578652, 128, Total Travel Time: 0 minutes
60848578654, 128, Total Mining Time: 0 minutes
60848578655, 128, Average Mining Time: 0.00 minutes
60848578657, 128, Mining to Simulation Time Ratio: 0.00%
60848578658, 128, Truck8
60848578660, 128, Total Operation Cycles: 0
60848578661, 128, Total Wait Time in Unload Queues: 0 minutes
60848578718, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578722, 128, Total Travel Time: 0 minutes
60848578726, 128, Total Mining Time: 0 minutes
60848578732, 128, Average Mining Time: 0.00 minutes
60848578734, 128, Mining to Simulation Time Ratio: 0.00%
60848578736, 128, Truck9
60848578738, 128, Total Operation Cycles: 0
60848578740, 128, Total Wait Time in Unload Queues: 0 minutes
60848578745, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578747, 128, Total Travel Time: 0 minutes
60848578750, 128, Total Mining Time: 0 minutes
60848578755, 128, Average Mining Time: 0.00 minutes
60848578758, 128, Mining to Simulation Time Ratio: 0.00%
60848578760, 128, Truck10
60848578762, 128, Total Operation Cycles: 0
60848578764, 128, Total Wait Time in Unload Queues: 0 minutes
60848578767, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578770, 128, Total Travel Time: 0 minutes
60848578774, 128, Total Mining Time: 0 minutes
60848578777, 128, Average Mining Time: 0.00 minutes
60848578781, 128, Mining to Simulation Time Ratio: 0.00%
60848578785, 128, Truck11
60848578788, 128, Total Operation Cycles: 0
60848578791, 128, Total Wait Time in Unload Queues: 0 minutes
60848578795, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578798, 128, Total Travel Time: 0 minutes
60848578802, 128, Total Mining Time: 0 minutes
60848578807, 128, Average Mining Time: 0.00 minutes
60848578812, 128, Mining to Simulation Time Ratio: 0.00%
60848578815, 128, Truck12
60848578817, 128, Total Operation Cycles: 0
60848578819, 128, Total Wait Time in Unload Queues: 0 minutes
60848578822, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578823, 128, Total Travel Time: 0 minutes
60848578824, 128, Total Mining Time: 0 minutes
60848578826, 128, Average Mining Time: 0.00 minutes
60848578828, 128, Mining to Simulation Time Ratio: 0.00%
60848578829, 128, Truck13
60848578830, 128, Total Operation Cycles: 0
60848578832, 128, Total Wait Time in Unload Queues: 0 minutes
60848578833, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578834, 128, Total Travel Time: 0 minutes
60848578836, 128, Total Mining Time: 0 minutes
60848578837, 128, Average Mining Time: 0.00 minutes
60848578839, 128, Mining to Simulation Time Ratio: 0.00%
60848578840, 128, Truck14
60848578842, 128, Total Operation Cycles: 0
60848578843, 128, Total Wait Time in Unload Queues: 0 minutes
60848578844, 128, Average Wait Time in Unload Queues: 0.00 minutes
60848578846, 128, Total Travel Time: 0 minutes
60848578847, 128, Total Mining Time: 0 minutes
60848578848, 128, Average Mining Time: 0.00 minutes
60848578850, 128, Mining to Simulation Time Ratio: 0.00%
60848578852, 128, Station0
60848578854, 128, Total Unloads: 0
60848578855, 128, Total Queue Used Time: 0 minutes
60848578857, 128, Average Queue Used Time: 0.00 minutes
60848578859, 128, Operation Time to No-Op Ratio: 0.00%
60848578860, 128, Station1
60848578861, 128, Total Unloads: 0
60848578863, 128, Total Queue Used Time: 0 minutes
60848578864, 128, Average Queue Used Time: 0.00 minutes
60848578866, 128, Operation Time to No-Op Ratio: 0.00%
60848578867, 128, Station2
60848578868, 128, Total Unloads: 0
60848578870, 128, Total Queue Used Time: 0 minutes
60848578871, 128, Average Queue Used Time: 0.00 minutes
60848578873, 128, Operation Time to No-Op Ratio: 0.00%
