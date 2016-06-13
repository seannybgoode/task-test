# Todo: Alter the complete_tasks method so that it only calls 'complete' on
#           non-completed task.
#       Add a remove_task method that removes only one task by id
#       Fix the Task object id, so that it is unique for each new task.
#       Fix other bugs.

# Note: - you cannot edit/change the TaskManager class
#       - You can create new objects, etc


class Task(object):

    def __init__(self, name):
        self._id = 0
        self._name = name
        self._completed = False

    def complete(self):
        _completed = True

    @property
    def is_completed(self):
        return self._completed

    @property
    def name(self):
        return self._name

    @property
    def id(self):
        return self._id


class TaskManager(object):

    def __init__(self):
        self.tasks = []

    def import_task(self, task):
        self.tasks.append(task)

    def complete_tasks(self):
        if len(self.tasks) > 0:
            if not all([task.is_completed for task in self.tasks]):
                for task in self.tasks:
                    task.complete()
                    print('task {name} completed'.format(name=task.name))

    def remove_tasks(self):
        while len(self.tasks) > 0:
            self.tasks.pop()


if __name__ == "__main__":
    task_manager = TaskManager()
    first_task = Task('first')
    second_task = Task('second')
    third_task = Task('third')

    task_manager.import_task(first_task)
    task_manager.import_task(second_task)
    task_manager.import_task(third_task)
    task_manager.complete_tasks()

    last_task = Task('last')
    task_manager.import_task(last_task)
    task_manager.complete_tasks()

    task_manager.remove_tasks()

