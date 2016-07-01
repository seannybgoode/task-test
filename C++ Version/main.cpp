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

#include <limits>

#include "BetterTaskManager.h"


int main () 
{
	BetterTaskManager task_manager;
	Task first_task ("!!nZ@xr492CCN;SDRC2#6CcN5UcCNq]*m44AhW`");
	Task second_task ("g}~x?C*n9K|LccN_YEL@<=44jkc.dB-v{!#;7*[[");
	Task third_task ("ekCcN,h9=!B46)j6acCN;`n68M2ZR2CCn^:CUw");
	Task fourth_task("");
        Task fifth_task("zzzz22zzz");
        
        task_manager.ImportTask(fourth_task);
        task_manager.ImportTask(fifth_task);
	task_manager.ImportTask(first_task);
	
        task_manager.RemoveTask(fifth_task.Id());
        
        task_manager.ImportTask(second_task);
	task_manager.ImportTask(third_task);
	task_manager.CompleteTasks();
	
        std::cout << "output should show all tasks except fifth (taskid 6)" << std::endl;
        
	Task last_task (">.`8tCcn{xsS3sa!G@{cCn(w},U+s)**sACc]NAn#");
	task_manager.ImportTask(last_task);
        
	task_manager.CompleteTasks();
	
	task_manager.RemoveTasks();
	
	std::cout << "Press ENTER to close... " << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
	return 0;
}
