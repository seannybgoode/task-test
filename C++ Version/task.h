// Todo: Alter the complete_tasks method so that it only calls 'complete' on
//           non-completed task.
//       Add a remove_task method that removes only one task by id
//
//       Upon calling Complete() on a task, set _value of that task object to the number of occurrences of the
//          string "CCN" (case in-sensitive) that appears in the task's name.
//
//       Fix the Task object id, so that it is unique for each new task.
//       Fix other bugs.

// Note: - you cannot edit/change the TaskManager class
//       - You can create new objects, etc

#ifndef __Task__
#define __Task__


#include <string>
#include <regex>

class Task {
        //static int _last_used_id;
        
        
        int _id;
	std::string _name;
	int _value;
	bool _completed;

	public:
		Task(std::string);
                
                void CountStrSequences();
		void Complete();

		bool IsCompleted() const { return _completed; }
		std::string Name() const { return _name; }
		int Id() const { return _id; }
};

//use anonymous namespace like you'd use a static member in java
namespace
{
    int _lastUsedId = 0;
}

Task::Task(std::string name) {
        
	_id = _lastUsedId ++; //give a unique id number
	_value = -1;
	_name = name;
	_completed = false;
}

/* Looks for the sequence of characters 'CCN' case in-sensitive*/
void Task::CountStrSequences(){
    
    int count = 0;
    std::regex reg("[cC]{2}[nN]{1}", std::regex_constants::extended);
    auto iterator = std::sregex_iterator (_name.begin(), _name.end(), reg);
    auto endOfSequence = std::sregex_iterator();
    
    while(iterator!=endOfSequence){
        count ++;
        iterator ++;
    }
    _value = count;
    std::cout << "Task value is: " << _value << "  Task ID is: " << _id << std::endl;
}

void Task::Complete() {
	_completed = true;
        CountStrSequences();
}





#endif



