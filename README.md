# CipherX
This repo is our team project on Data structure and algorithm. Our team name is CipherX and we have to create a model which schedules TV programs.


TV Channel Scheduler:

  You are to build a TV Channel Scheduler. The Scheduler works for family members who want to record their favorite TV series so that they can watch them later and     get notified by the Scheduler when they have time (it knows their availability slots - randomly initialized). There are N members in a family, each having their      favorite series out of a total of M. Multiple members may love the same series. However, the Scheduler cannot schedule a series if there is a conflict of interest.   Also, members want to get on time for p slots. The Scheduler needs to minimize total episode misses.

Comments:

  ● Input data will be a file (can be txt or xls) with records in the format:
  
    ○ Family member name
  
    ○ Availability slots (will be a set of time intervals for each of 7 days)
    
    ○ Set (S) of favorite TV series (S <= M)
  
  ● Conflict of interest means two or more overlapping intervals
  
  ● “Also, members want to get on time for p slots”: This means for at least p slots (out of S), every member wants to be on time and not wait.
