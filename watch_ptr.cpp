#include "watch_ptr.hpp"
#include "Watchable.hpp"

void watch_ptr_base::link(const Watchable* watchable_object)
{
    assert(previous == nullptr);
    assert(next == nullptr);

    ptr = watchable_object;

    if (watchable_object != nullptr)
    {
        previous = &(watchable_object->m_watchers);
        next = watchable_object->m_watchers.next;

        if (watchable_object->m_watchers.next != nullptr)
        {
            watchable_object->m_watchers.next->previous = this;
        }

        watchable_object->m_watchers.next = this;
    }
}

void watch_ptr_base::unlink()
{
    if (next != nullptr)
    {
        next->previous = previous;
    }

    if (previous != nullptr)
    {
        previous->next = next;
    }

    next = nullptr;
    previous = nullptr;
}