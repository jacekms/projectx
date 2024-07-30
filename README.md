//TODO  more testing, improve error handling, test with monotonic scalable rate clock, more gtests, sim v2 multithreaded, to the moon

1. Build

$ ./xbuild.sh 

2. Run

$ ./build/sim_h3_mining 15 3 120

3. Check the log file 'SH3M_Log.txt'

Example log:

```
real_time,    sim_clock, sim_clock in messages
microseconds, minutes,   message time values in minutes

106069502793, 0, Log started. Output to file='SH3M_Log.txt'
106069502811, 0, Timestamp unit [us]
106069502859, 0, Truck0 [Mining] till time=264 (for 264)
106069502863, 0, Truck1 [Mining] till time=104 (for 104)
106069502869, 0, Truck2 [Mining] till time=192 (for 192)
106069502872, 0, Truck3 [Mining] till time=97 (for 97)
106069502887, 0, Truck4 [Mining] till time=248 (for 248)
106069502892, 0, Truck5 [Mining] till time=86 (for 86)
106069502895, 0, Truck6 [Mining] till time=246 (for 246)
106069502899, 0, Truck7 [Mining] till time=57 (for 57)
106069502906, 0, Truck8 [Mining] till time=212 (for 212)
106069502910, 0, Truck9 [Mining] till time=293 (for 293)
106069502914, 0, Truck10 [Mining] till time=270 (for 270)
106069502922, 0, Sim: time now=0 < end=250
106069502925, 0, Sim: Truck7 nearest event in state [Mining] time=57
106069502927, 0, Sim: time now=0 < end=250
106069502928, 0, Sim: Time step now=0 new_time=57
106069502937, 57, Truck7 mined for 0.9 hours.
106069502937, 57, Truck7 state [Mining] transition to [TravelingToUnload]
106069502938, 57, Truck7 [TravelingToUnload] till time=87 (for 30)
106069502939, 57, Sim: Truck7 executed event in [TravelingToUnload] state
106069502940, 57, Sim: Truck5 nearest event in state [Mining] time=86
106069502941, 57, Sim: time now=57 < end=250
106069502942, 57, Sim: Time step now=57 new_time=86
106069502943, 86, Truck5 mined for 1.4 hours.
106069502944, 86, Truck5 state [Mining] transition to [TravelingToUnload]
106069502944, 86, Truck5 [TravelingToUnload] till time=116 (for 30)
106069502945, 86, Sim: Truck5 executed event in [TravelingToUnload] state
106069502946, 86, Sim: Truck7 nearest event in state [TravelingToUnload] time=87
106069502947, 86, Sim: time now=86 < end=250
106069502947, 86, Sim: Time step now=86 new_time=87
106069502948, 87, Truck7 traveling to unload station.
106069502949, 87, Truck7 state [TravelingToUnload] transition to [WaitingInQueue]
106069502949, 87, Truck7 [WaitingInQueue] till time=87 (for 0)
106069502950, 87, Sim: Truck7 executed event in [WaitingInQueue] state
106069502951, 87, Sim: Station0 queue add Truck7, nearest unload start time=0
106069502953, 87, Sim: To Station0 not occupied QLen=0 ADD Truck7 [WaitingInQueue] unload finish time=92
106069502953, 87, Truck7 waiting in queue to unload.
106069502954, 87, Truck7 state [WaitingInQueue] transition to [Unloading]
106069502955, 87, Truck7 [Unloading] till time=92 (for 5)
106069502956, 87, Sim: Truck7 nearest event in state [Unloading] time=92
106069502957, 87, Sim: Station0 Unloaded Truck7 state [Unloading] time=92
106069502958, 92, Sim: time now=92 < end=250
106069502959, 92, Sim: Time step now=92 new_time=92
106069502959, 92, Truck7 waiting in queue and unloading for 5.
106069502960, 92, Truck7 state [Unloading] transition to [TravelingToMine]
106069502960, 92, Truck7 [TravelingToMine] till time=122 (for 30)
106069502961, 92, Sim: Truck7 executed event in [TravelingToMine] state
106069502962, 92, Sim: Truck3 nearest event in state [Mining] time=97
106069502963, 92, Sim: time now=92 < end=250
106069502964, 92, Sim: Time step now=92 new_time=97
106069502964, 97, Truck3 mined for 1.6 hours.
106069502965, 97, Truck3 state [Mining] transition to [TravelingToUnload]
106069502965, 97, Truck3 [TravelingToUnload] till time=127 (for 30)
106069502966, 97, Sim: Truck3 executed event in [TravelingToUnload] state
106069502967, 97, Sim: Truck1 nearest event in state [Mining] time=104
106069502968, 97, Sim: time now=97 < end=250
106069502969, 97, Sim: Time step now=97 new_time=104
106069502969, 104, Truck1 mined for 1.7 hours.
106069502970, 104, Truck1 state [Mining] transition to [TravelingToUnload]
106069502970, 104, Truck1 [TravelingToUnload] till time=134 (for 30)
106069502971, 104, Sim: Truck1 executed event in [TravelingToUnload] state
106069502972, 104, Sim: Truck5 nearest event in state [TravelingToUnload] time=116
106069502973, 104, Sim: time now=104 < end=250
106069502973, 104, Sim: Time step now=104 new_time=116
106069502974, 116, Truck5 traveling to unload station.
106069502975, 116, Truck5 state [TravelingToUnload] transition to [WaitingInQueue]
106069502991, 116, Truck5 [WaitingInQueue] till time=116 (for 0)
106069502992, 116, Sim: Truck5 executed event in [WaitingInQueue] state
106069502993, 116, Sim: Station1 queue add Truck5, nearest unload start time=0
106069502994, 116, Sim: To Station1 not occupied QLen=0 ADD Truck5 [WaitingInQueue] unload finish time=121
106069502994, 116, Truck5 waiting in queue to unload.
106069502995, 116, Truck5 state [WaitingInQueue] transition to [Unloading]
106069502995, 116, Truck5 [Unloading] till time=121 (for 5)
106069502997, 116, Sim: Truck5 nearest event in state [Unloading] time=121
106069502998, 116, Sim: Station1 Unloaded Truck5 state [Unloading] time=121
106069502998, 121, Sim: time now=121 < end=250
106069502999, 121, Sim: Time step now=121 new_time=121
106069503000, 121, Truck5 waiting in queue and unloading for 5.
106069503000, 121, Truck5 state [Unloading] transition to [TravelingToMine]
106069503001, 121, Truck5 [TravelingToMine] till time=151 (for 30)
106069503001, 121, Sim: Truck5 executed event in [TravelingToMine] state
106069503002, 121, Sim: Truck7 nearest event in state [TravelingToMine] time=122
106069503003, 121, Sim: time now=121 < end=250
106069503004, 121, Sim: Time step now=121 new_time=122
106069503004, 122, Truck7 traveling to mining site.
106069503005, 122, Truck7 state [TravelingToMine] transition to [Mining]
106069503006, 122, Truck7 [Mining] till time=259 (for 137)
106069503006, 122, Sim: Truck7 executed event in [Mining] state
106069503007, 122, Sim: Truck3 nearest event in state [TravelingToUnload] time=127
106069503008, 122, Sim: time now=122 < end=250
106069503009, 122, Sim: Time step now=122 new_time=127
106069503009, 127, Truck3 traveling to unload station.
106069503010, 127, Truck3 state [TravelingToUnload] transition to [WaitingInQueue]
106069503010, 127, Truck3 [WaitingInQueue] till time=127 (for 0)
106069503011, 127, Sim: Truck3 executed event in [WaitingInQueue] state
106069503012, 127, Sim: Station2 queue add Truck3, nearest unload start time=0
106069503013, 127, Sim: To Station2 not occupied QLen=0 ADD Truck3 [WaitingInQueue] unload finish time=132
106069503013, 127, Truck3 waiting in queue to unload.
106069503014, 127, Truck3 state [WaitingInQueue] transition to [Unloading]
106069503014, 127, Truck3 [Unloading] till time=132 (for 5)
106069503015, 127, Sim: Truck3 nearest event in state [Unloading] time=132
106069503016, 127, Sim: Station2 Unloaded Truck3 state [Unloading] time=132
106069503017, 132, Sim: time now=132 < end=250
106069503017, 132, Sim: Time step now=132 new_time=132
106069503018, 132, Truck3 waiting in queue and unloading for 5.
106069503019, 132, Truck3 state [Unloading] transition to [TravelingToMine]
106069503019, 132, Truck3 [TravelingToMine] till time=162 (for 30)
106069503020, 132, Sim: Truck3 executed event in [TravelingToMine] state
106069503021, 132, Sim: Truck1 nearest event in state [TravelingToUnload] time=134
106069503022, 132, Sim: time now=132 < end=250
106069503022, 132, Sim: Time step now=132 new_time=134
106069503023, 134, Truck1 traveling to unload station.
106069503023, 134, Truck1 state [TravelingToUnload] transition to [WaitingInQueue]
106069503024, 134, Truck1 [WaitingInQueue] till time=134 (for 0)
106069503024, 134, Sim: Truck1 executed event in [WaitingInQueue] state
106069503025, 134, Sim: Station0 queue add Truck1, nearest unload start time=92
106069503026, 134, Sim: To Station0 not occupied QLen=0 ADD Truck1 [WaitingInQueue] unload finish time=139
106069503026, 134, Truck1 waiting in queue to unload.
106069503027, 134, Truck1 state [WaitingInQueue] transition to [Unloading]
106069503027, 134, Truck1 [Unloading] till time=139 (for 5)
106069503029, 134, Sim: Truck1 nearest event in state [Unloading] time=139
106069503030, 134, Sim: Station0 Unloaded Truck1 state [Unloading] time=139
106069503030, 139, Sim: time now=139 < end=250
106069503031, 139, Sim: Time step now=139 new_time=139
106069503031, 139, Truck1 waiting in queue and unloading for 5.
106069503032, 139, Truck1 state [Unloading] transition to [TravelingToMine]
106069503040, 139, Truck1 [TravelingToMine] till time=169 (for 30)
106069503040, 139, Sim: Truck1 executed event in [TravelingToMine] state
106069503041, 139, Sim: Truck5 nearest event in state [TravelingToMine] time=151
106069503042, 139, Sim: time now=139 < end=250
106069503043, 139, Sim: Time step now=139 new_time=151
106069503043, 151, Truck5 traveling to mining site.
106069503044, 151, Truck5 state [TravelingToMine] transition to [Mining]
106069503045, 151, Truck5 [Mining] till time=367 (for 216)
106069503045, 151, Sim: Truck5 executed event in [Mining] state
106069503046, 151, Sim: Truck3 nearest event in state [TravelingToMine] time=162
106069503047, 151, Sim: time now=151 < end=250
106069503048, 151, Sim: Time step now=151 new_time=162
106069503048, 162, Truck3 traveling to mining site.
106069503049, 162, Truck3 state [TravelingToMine] transition to [Mining]
106069503049, 162, Truck3 [Mining] till time=317 (for 155)
106069503050, 162, Sim: Truck3 executed event in [Mining] state
106069503051, 162, Sim: Truck1 nearest event in state [TravelingToMine] time=169
106069503051, 162, Sim: time now=162 < end=250
106069503052, 162, Sim: Time step now=162 new_time=169
106069503052, 169, Truck1 traveling to mining site.
106069503053, 169, Truck1 state [TravelingToMine] transition to [Mining]
106069503054, 169, Truck1 [Mining] till time=448 (for 279)
106069503054, 169, Sim: Truck1 executed event in [Mining] state
106069503055, 169, Sim: Truck2 nearest event in state [Mining] time=192
106069503056, 169, Sim: time now=169 < end=250
106069503057, 169, Sim: Time step now=169 new_time=192
106069503057, 192, Truck2 mined for 3.2 hours.
106069503058, 192, Truck2 state [Mining] transition to [TravelingToUnload]
106069503059, 192, Truck2 [TravelingToUnload] till time=222 (for 30)
106069503059, 192, Sim: Truck2 executed event in [TravelingToUnload] state
106069503060, 192, Sim: Truck8 nearest event in state [Mining] time=212
106069503061, 192, Sim: time now=192 < end=250
106069503062, 192, Sim: Time step now=192 new_time=212
106069503062, 212, Truck8 mined for 3.5 hours.
106069503063, 212, Truck8 state [Mining] transition to [TravelingToUnload]
106069503063, 212, Truck8 [TravelingToUnload] till time=242 (for 30)
106069503064, 212, Sim: Truck8 executed event in [TravelingToUnload] state
106069503065, 212, Sim: Truck2 nearest event in state [TravelingToUnload] time=222
106069503066, 212, Sim: time now=212 < end=250
106069503066, 212, Sim: Time step now=212 new_time=222
106069503067, 222, Truck2 traveling to unload station.
106069503067, 222, Truck2 state [TravelingToUnload] transition to [WaitingInQueue]
106069503068, 222, Truck2 [WaitingInQueue] till time=222 (for 0)
106069503068, 222, Sim: Truck2 executed event in [WaitingInQueue] state
106069503069, 222, Sim: Station1 queue add Truck2, nearest unload start time=121
106069503070, 222, Sim: To Station1 not occupied QLen=0 ADD Truck2 [WaitingInQueue] unload finish time=227
106069503071, 222, Truck2 waiting in queue to unload.
106069503071, 222, Truck2 state [WaitingInQueue] transition to [Unloading]
106069503072, 222, Truck2 [Unloading] till time=227 (for 5)
106069503073, 222, Sim: Truck2 nearest event in state [Unloading] time=227
106069503074, 222, Sim: Station1 Unloaded Truck2 state [Unloading] time=227
106069503074, 227, Sim: time now=227 < end=250
106069503075, 227, Sim: Time step now=227 new_time=227
106069503076, 227, Truck2 waiting in queue and unloading for 5.
106069503076, 227, Truck2 state [Unloading] transition to [TravelingToMine]
106069503077, 227, Truck2 [TravelingToMine] till time=257 (for 30)
106069503077, 227, Sim: Truck2 executed event in [TravelingToMine] state
106069503078, 227, Sim: Truck8 nearest event in state [TravelingToUnload] time=242
106069503079, 227, Sim: time now=227 < end=250
106069503080, 227, Sim: Time step now=227 new_time=242
106069503080, 242, Truck8 traveling to unload station.
106069503081, 242, Truck8 state [TravelingToUnload] transition to [WaitingInQueue]
106069503081, 242, Truck8 [WaitingInQueue] till time=242 (for 0)
106069503082, 242, Sim: Truck8 executed event in [WaitingInQueue] state
106069503088, 242, Sim: Station2 queue add Truck8, nearest unload start time=132
106069503089, 242, Sim: To Station2 not occupied QLen=0 ADD Truck8 [WaitingInQueue] unload finish time=247
106069503089, 242, Truck8 waiting in queue to unload.
106069503089, 242, Truck8 state [WaitingInQueue] transition to [Unloading]
106069503090, 242, Truck8 [Unloading] till time=247 (for 5)
106069503091, 242, Sim: Truck6 nearest event in state [Mining] time=246
106069503092, 242, Sim: time now=242 < end=250
106069503093, 242, Sim: Time step now=242 new_time=246
106069503094, 246, Truck6 mined for 4.1 hours.
106069503094, 246, Truck6 state [Mining] transition to [TravelingToUnload]
106069503095, 246, Truck6 [TravelingToUnload] till time=276 (for 30)
106069503095, 246, Sim: Truck6 executed event in [TravelingToUnload] state
106069503096, 246, Sim: Truck8 nearest event in state [Unloading] time=247
106069503097, 246, Sim: Station2 Unloaded Truck8 state [Unloading] time=247
106069503098, 247, Sim: time now=247 < end=250
106069503098, 247, Sim: Time step now=247 new_time=247
106069503099, 247, Truck8 waiting in queue and unloading for 5.
106069503099, 247, Truck8 state [Unloading] transition to [TravelingToMine]
106069503100, 247, Truck8 [TravelingToMine] till time=277 (for 30)
106069503101, 247, Sim: Truck8 executed event in [TravelingToMine] state
106069503102, 247, Sim: Truck4 nearest event in state [Mining] time=248
106069503102, 247, Sim: time now=247 < end=250
106069503103, 247, Sim: Time step now=247 new_time=248
106069503104, 248, Truck4 mined for 4.1 hours.
106069503104, 248, Truck4 state [Mining] transition to [TravelingToUnload]
106069503105, 248, Truck4 [TravelingToUnload] till time=278 (for 30)
106069503105, 248, Sim: Truck4 executed event in [TravelingToUnload] state
106069503106, 248, Sim: Truck2 nearest event in state [TravelingToMine] time=257
106069503107, 248, Sim: time now=248 < end=250
106069503108, 248, Sim: Time step now=248 new_time=257
106069503108, 257, Truck2 traveling to mining site.
106069503109, 257, Truck2 state [TravelingToMine] transition to [Mining]
106069503109, 257, Truck2 [Mining] till time=307 (for 50)
106069503110, 257, Sim: Truck2 executed event in [Mining] state
106069503111, 257, Sim: Truck7 nearest event in state [Mining] time=259
106069503112, 257, Simulation done after 250 min
106069503112, 257, ========================= STATISTICS ========================
106069503113, 257, Simulation
106069503113, 257, Total Unloads: 6
106069503114, 257, Total Mine Time: 837 minutes
106069503114, 257, Total Wait in Unload Queue: 30 minutes
106069503115, 257, Total Operation Cycles: 6
106069503115, 257, ========================= ========== ========================
106069503116, 257, Truck0
106069503116, 257, Total Operation Cycles: 0
106069503117, 257, Total Wait Time in Unload Queues: 0 minutes
106069503118, 257, Average Wait Time in Unload Queues: 0.00 minutes
106069503118, 257, Total Travel Time: 0 minutes
106069503118, 257, Total Mining Time: 0 minutes
106069503119, 257, Average Mining Time: 0.00 minutes
106069503120, 257, Mining to Simulation Time Ratio: 0.00%
106069503120, 257, Truck1
106069503121, 257, Total Operation Cycles: 1
106069503121, 257, Total Wait Time in Unload Queues: 5 minutes
106069503122, 257, Average Wait Time in Unload Queues: 5.00 minutes
106069503122, 257, Total Travel Time: 60 minutes
106069503123, 257, Total Mining Time: 104 minutes
106069503125, 257, Average Mining Time: 104.00 minutes
106069503126, 257, Mining to Simulation Time Ratio: 41.60%
106069503126, 257, Truck2
106069503127, 257, Total Operation Cycles: 1
106069503127, 257, Total Wait Time in Unload Queues: 5 minutes
106069503128, 257, Average Wait Time in Unload Queues: 5.00 minutes
106069503128, 257, Total Travel Time: 60 minutes
106069503128, 257, Total Mining Time: 192 minutes
106069503129, 257, Average Mining Time: 192.00 minutes
106069503131, 257, Mining to Simulation Time Ratio: 76.80%
106069503131, 257, Truck3
106069503131, 257, Total Operation Cycles: 1
106069503132, 257, Total Wait Time in Unload Queues: 5 minutes
106069503138, 257, Average Wait Time in Unload Queues: 5.00 minutes
106069503138, 257, Total Travel Time: 60 minutes
106069503139, 257, Total Mining Time: 97 minutes
106069503139, 257, Average Mining Time: 97.00 minutes
106069503140, 257, Mining to Simulation Time Ratio: 38.80%
106069503141, 257, Truck4
106069503141, 257, Total Operation Cycles: 0
106069503142, 257, Total Wait Time in Unload Queues: 0 minutes
106069503142, 257, Average Wait Time in Unload Queues: 0.00 minutes
106069503143, 257, Total Travel Time: 0 minutes
106069503143, 257, Total Mining Time: 248 minutes
106069503144, 257, Average Mining Time: 0.00 minutes
106069503144, 257, Mining to Simulation Time Ratio: 99.20%
106069503145, 257, Truck5
106069503145, 257, Total Operation Cycles: 1
106069503146, 257, Total Wait Time in Unload Queues: 5 minutes
106069503146, 257, Average Wait Time in Unload Queues: 5.00 minutes
106069503147, 257, Total Travel Time: 60 minutes
106069503147, 257, Total Mining Time: 86 minutes
106069503148, 257, Average Mining Time: 86.00 minutes
106069503149, 257, Mining to Simulation Time Ratio: 34.40%
106069503149, 257, Truck6
106069503150, 257, Total Operation Cycles: 0
106069503150, 257, Total Wait Time in Unload Queues: 0 minutes
106069503150, 257, Average Wait Time in Unload Queues: 0.00 minutes
106069503151, 257, Total Travel Time: 0 minutes
106069503151, 257, Total Mining Time: 246 minutes
106069503152, 257, Average Mining Time: 0.00 minutes
106069503153, 257, Mining to Simulation Time Ratio: 98.40%
106069503153, 257, Truck7
106069503154, 257, Total Operation Cycles: 1
106069503154, 257, Total Wait Time in Unload Queues: 5 minutes
106069503155, 257, Average Wait Time in Unload Queues: 5.00 minutes
106069503155, 257, Total Travel Time: 60 minutes
106069503155, 257, Total Mining Time: 57 minutes
106069503156, 257, Average Mining Time: 57.00 minutes
106069503157, 257, Mining to Simulation Time Ratio: 22.80%
106069503157, 257, Truck8
106069503158, 257, Total Operation Cycles: 0
106069503158, 257, Total Wait Time in Unload Queues: 5 minutes
106069503159, 257, Average Wait Time in Unload Queues: 0.00 minutes
106069503159, 257, Total Travel Time: 30 minutes
106069503159, 257, Total Mining Time: 212 minutes
106069503160, 257, Average Mining Time: 0.00 minutes
106069503161, 257, Mining to Simulation Time Ratio: 84.80%
106069503161, 257, Truck9
106069503162, 257, Total Operation Cycles: 0
106069503162, 257, Total Wait Time in Unload Queues: 0 minutes
106069503163, 257, Average Wait Time in Unload Queues: 0.00 minutes
106069503163, 257, Total Travel Time: 0 minutes
106069503164, 257, Total Mining Time: 0 minutes
106069503164, 257, Average Mining Time: 0.00 minutes
106069503165, 257, Mining to Simulation Time Ratio: 0.00%
106069503165, 257, Truck10
106069503166, 257, Total Operation Cycles: 0
106069503166, 257, Total Wait Time in Unload Queues: 0 minutes
106069503166, 257, Average Wait Time in Unload Queues: 0.00 minutes
106069503167, 257, Total Travel Time: 0 minutes
106069503167, 257, Total Mining Time: 0 minutes
106069503168, 257, Average Mining Time: 0.00 minutes
106069503168, 257, Mining to Simulation Time Ratio: 0.00%
106069503169, 257, ========================= ========== ========================
106069503169, 257, Station0
106069503170, 257, Total Unloads: 2
106069503170, 257, Total Queue Used Time: 10 minutes
106069503171, 257, Average Queue Used Time: 5.00 minutes
106069503172, 257, Operation Time to No-Op Ratio: 4.00%
106069503172, 257, Station1
106069503173, 257, Total Unloads: 2
106069503173, 257, Total Queue Used Time: 10 minutes
106069503174, 257, Average Queue Used Time: 5.00 minutes
106069503174, 257, Operation Time to No-Op Ratio: 4.00%
106069503175, 257, Station2
106069503175, 257, Total Unloads: 2
106069503175, 257, Total Queue Used Time: 10 minutes
106069503176, 257, Average Queue Used Time: 5.00 minutes
106069503176, 257, Operation Time to No-Op Ratio: 4.00%
106069503177, 257, ========================= ========== ========================
