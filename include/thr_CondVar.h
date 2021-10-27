#ifndef thr_CondVar_h
#define thr_CondVar_h

// Begin local includes

#include <thr_ThreadingModel.h>
#include <thr_Mutex.h>
#include <SMABasAtiCondVar.h>

// End local includes

//-----------------------------------------------------------------
// PTHREADS IMPLEMENTATION
//-----------------------------------------------------------------
#if defined HKS_PTHREADS

class thr_CondVar  : public SMABasAtiCondVar
{
 public:
  thr_CondVar();
  ~thr_CondVar();
  virtual void Lock();
  virtual void Unlock();
  virtual void WaitForSignal(const int timeout = 0);
  virtual void Signal();
  void ResetSignal(){}

  virtual int id() const { return 503; }

 private:
  void*     m_threadWaitCv;
  void*     m_threadWaitMutex;
};

//-----------------------------------------------------------------
// WINDOWS THREADS IMPLEMENTATION
//-----------------------------------------------------------------
#elif defined HKS_WINTHREADS

class thr_CondVar  : public SMABasAtiCondVar
{
public:
    thr_CondVar();
    ~thr_CondVar();
    virtual void Lock();
    virtual void Unlock();
    virtual void WaitForSignal(const int timeout = 0);
    virtual void Signal();

    virtual int id() const { return 522; }

    void ResetSignal() { }
  
private:
    // Basic events necessary for condition variable.
    void*           m_threadWaitEvent;
    void*           m_threadWaitMutex;

    // Additional members required to handle missed signals on 
    // Windows because of APC's.
    thr_Mutex       m_signalLock;
    volatile int    m_waiterCount;
    volatile int    m_signalled;
};

//-----------------------------------------------------------------
// NO THREADS
//-----------------------------------------------------------------
#else

class thr_CondVar  : public SMABasAtiCondVar
{

 public:
  thr_CondVar() {}
  ~thr_CondVar() {}
  virtual void Lock() {}
  virtual void Unlock() {}
  virtual void WaitForSignal(const int timeout = 0) {}
  virtual void Signal() {}

  virtual int id() const { return 523; }

  void ResetSignal() {}
  
};

#endif /* HKS_PTHREADS, HKS_WINTHREADS, NO THREADS */

#endif /* thr_CondVar_h */
