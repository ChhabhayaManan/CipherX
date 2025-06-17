  # CipherX - TV Channel Scheduler
  
## Overview
CipherX is a team project focused on applying Data Structures and Algorithms to develop a **TV Channel Scheduler**. This scheduler is designed for families to manage and record their favorite TV shows based on their availability, minimizing missed episodes and resolving scheduling conflicts effectively.

## TV Channel Scheduler:

  You are to build a TV Channel Scheduler. The Scheduler works for family members who want to record their favorite TV series so that they can watch them later and     get notified by the Scheduler when they have time (it knows their availability slots - randomly initialized). There are N members in a family, each having their      favorite series out of a total of M. Multiple members may love the same series. However, the Scheduler cannot schedule a series if there is a conflict of interest.   Also, members want to get on time for p slots. The Scheduler needs to minimize total episode misses.

Comments:

  ● Input data will be a file (can be txt or xls) with records in the format:
  
    ○ Family member name
  
    ○ Availability slots (will be a set of time intervals for each of 7 days)
    
    ○ Set (S) of favorite TV series (S <= M)
  
  ● Conflict of interest means two or more overlapping intervals
  
  ● “Also, members want to get on time for p slots”: This means for at least p slots (out of S), every member wants to be on time and not wait.

---

## Features
- **Scheduling Management:** Records favorite TV series for family members and schedules them based on availability.
- **Conflict Resolution:** Detects overlapping availability slots to prevent scheduling conflicts.
- **Minimizes Missed Episodes:** Ensures members can catch up with their favorite series without clashes.

---

## Input Requirements
The input data should be provided in a **text (.txt)** or **Excel (.xls)** file with the following structure:
- **Family Member Name**
- **Availability Slots** (time intervals for each day of the week)
- **Favorite TV Series (Set S)**: Each member can have a subset of favorite shows (S <= M).

**Note:** Conflict of interest occurs when two or more slots overlap, and members aim to attend at least **p slots** without delays.

---

- **schedule4 Folder:** Contains the code for the GUI application built with Windows Forms.
- **TVchennelSchedular.cpp:** Command-line version of the scheduler.
- **Capstone Project Documentation:** Includes project details and presentations.

---

## Usage
### GUI Application
1. Open the `schedule4.sln` file in Visual Studio.
2. Build and run the application.
3. Use the graphical interface to load input files and view schedules.

### Command-Line Application
1. Compile `TVchennelSchedular.cpp` using any C++ compiler.
2. Execute the program in the terminal:
```
./TVchennelSchedular
```
3. Follow on-screen prompts to load input files and view schedules.

---

## Algorithms Used
- **Greedy Scheduling Algorithm:** Prioritizes slots with maximum member availability for a particular show.
- **Conflict Detection Algorithm:** Checks overlapping slots and resolves conflicts by minimizing episode misses.
- **Priority Queue Optimization:** Ensures members with higher preferences are scheduled first.

---

## Key Functions
- **Slot Conversion:** Converts time slots between integer values (1-168) and string representations (e.g., MON 0-1).
- **Conflict Detection:** Validates overlapping intervals to resolve conflicts.
- **Scheduling Logic:** Assigns optimal time slots for shows based on member preferences.
- **User Interaction:** Provides options to schedule shows and view individual schedules.

---

## Team Members
- **Manan Chhabhaya**
- **Kresha Vora**
- **Anushka Prajapati**
- **Kashyap Ajudiya**
