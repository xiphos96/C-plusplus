#include "ace/Synch.h"
#include "ace/Task.h"
#include "ace/Hash_Map_Manager.h"

typedef ACE_Hash_Map_Manager<const char *, void *, ACE_Null_Mutex>
Map;
// Listing 1 code/ch14
// Client-specific context information.
class ClientContext
{
public:
  void *get_attribute (const char *name);
  void set_attribute (const char *name, void *value);

private:
  Map attributeMap_;
};
// Listing 1


void*
ClientContext::get_attribute (const char*name)
{
  void * value;
  attributeMap_.find (name, value);
  return value;
}

void
ClientContext::set_attribute (const char *name, void *value)
{
  attributeMap_.bind (name, value);
}

// Listing 2 code/ch14
class HA_CommandHandler : public ACE_Task<ACE_MT_SYNCH>
{
public:
  virtual int svc (void)
  {
    ACE_thread_t tid = this->thr_mgr ()->thr_self ();
    // Set our identifier in TSS.
    this->tss_ctx_->set_attribute ("thread_id", &tid);

    while (handle_requests () > 0)
      ;

    return 0;
  }

  int handle_requests (void)
  {
    ACE_thread_t *tid =
      (ACE_thread_t*)this->tss_ctx_->get_attribute ("thread_id");
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("(%t) TSS TID: %d \n"),
                *tid));

    // do work.
    return -1;
  }

private:
  ACE_TSS<ClientContext> tss_ctx_;
};
// Listing 2

int ACE_TMAIN (int, ACE_TCHAR *[])
{
  HA_CommandHandler handler;
  handler.activate (THR_NEW_LWP | THR_JOINABLE, 5);
  handler.wait ();
  return 0;
}

