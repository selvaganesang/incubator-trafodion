///////////////////////////////////////////////////////////////////////////////
//
// @@@ START COPYRIGHT @@@
//
// (C) Copyright 2009-2014 Hewlett-Packard Development Company, L.P.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
// @@@ END COPYRIGHT @@@
//
///////////////////////////////////////////////////////////////////////////////

#ifndef REQWORKER_H
#define REQWORKER_H

#include <pthread.h>

class CReqWorker
{
public:
    CReqWorker();
    virtual ~CReqWorker();

    static void startReqWorkers();
    static void shutdownWork();

    void reqWorkerThread();

    void shutdown() { shutdown_ = true; }

    // Define the number of request worker threads
    static const int NUM_WORKERS = 1;

private:

    bool shutdown_;

    static pthread_t workerIds[NUM_WORKERS];
    static CReqWorker * worker[NUM_WORKERS];
};

#endif