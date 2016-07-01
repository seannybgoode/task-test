
/* 
 * File:   BetterTaskManager.h
 * Author: Sean Brophy
 *
 * Based on task_manager.h. 
 * 
 * Created on June 30, 2016, 7:08 PM
 */

#include "task_manager.h"
#include "task.h"
#include <vector>
#include <iostream>
#include <algorithm>

#ifndef BETTERTASKMANAGER_H
#define BETTERTASKMANAGER_H


//bypassing TaskManager completely, since _tasks is private by default, 
//accessing it can't be done except with wacky hacks

class BetterTaskManager
{
    //made myTasks protected, so the next programmer can actually extend this class if needed
    protected:
        std::vector<Task> _myTasks;
    public:
        
        bool RemoveTask(int id);
        void RemoveTasks();
        void ImportTask(Task task);
        void CompleteTasks();
        
};


void BetterTaskManager::CompleteTasks() {
    if (!_myTasks.empty()) {
        if (!std::all_of(_myTasks.begin(), _myTasks.end(), [](Task& task){return task.IsCompleted();})) {
            for (auto &task : _myTasks) {
                if(!task.IsCompleted()){    
                    task.Complete();
                    std::cout << "task " << task.Name() << " completed." << std::endl;
                }
            }
        }
    }
}

void BetterTaskManager::ImportTask(Task task)
{
    _myTasks.push_back(task);
}

//assuming unsorted list, if it were sorted i'd use something < O(n)
//returns true if the item was removed, returns false if the item was not found
bool BetterTaskManager::RemoveTask(int id)
{
    std::vector<Task>::iterator end = _myTasks.end();
    std::vector<Task>::iterator begin = _myTasks.begin();
    
    int i = 0;
    for(; begin < end; begin++, i++)
    {
        if(_myTasks.at(i).Id() == id)
        {
            _myTasks.erase(begin);
            return true;
        }
    }
    return false;
    
}

void BetterTaskManager::RemoveTasks()
{
     _myTasks.erase(_myTasks.begin(), _myTasks.end());
    _myTasks.clear();
}

#endif /* BETTERTASKMANAGER_H */

