# Todo: Alter the complete_tasks method so that it only calls 'complete' on
#           non-completed task.
#       Add a remove_task method that removes only one task by id
#
#       Upon calling complete() on a task, set _value of that task object to the number of occurrences of the
#           string "CCN" (case in-sensitive) that appears in the task's name.
#
#       Fix the Task object id, so that it is unique for each new task.
#       Fix other bugs.

# Note: - you cannot edit/change the TaskManager class
#       - You can create new objects, etc
import uuid

class Task(object):

    def __init__(self, name):
        self._id = uuid.uuid4().hex
        self._name = name
        self._value = 0
        self._completed = False

    def complete(self):
        if self._completed:
            return
        else:
            self._completed = True
            len_counter = len(self._name)
            lower_name = self._name.lower()
            if len_counter < 3:
                return
            i = 3
            while i < len_counter:
                sub_string = lower_name[i-3:i]
                if 'ccn' in sub_string:
                    self._value += 1
                i += 1

    @property
    def is_completed(self):
        return self._completed

    @property
    def name(self):
        return self._name

    @property
    def id(self):
        return self._id

    @property
    def value(self):
        return self._value


# This class cannot be edited directly
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
