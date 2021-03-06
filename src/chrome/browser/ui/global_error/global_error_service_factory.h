// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_GLOBAL_ERROR_GLOBAL_ERROR_SERVICE_FACTORY_H_
#define CHROME_BROWSER_UI_GLOBAL_ERROR_GLOBAL_ERROR_SERVICE_FACTORY_H_

#include "base/basictypes.h"
#include "base/compiler_specific.h"
#include "base/memory/singleton.h"
#include "chrome/browser/profiles/profile_keyed_service_factory.h"

class GlobalErrorService;

// Singleton that owns all GlobalErrorService and associates them with
// Profiles. Listens for the Profile's destruction notification and cleans up
// the associated GlobalErrorService.
class GlobalErrorServiceFactory : public ProfileKeyedServiceFactory {
 public:
  static GlobalErrorService* GetForProfile(Profile* profile);

  static GlobalErrorServiceFactory* GetInstance();

 private:
  friend struct DefaultSingletonTraits<GlobalErrorServiceFactory>;

  GlobalErrorServiceFactory();
  virtual ~GlobalErrorServiceFactory();

  // ProfileKeyedServiceFactory:
  virtual ProfileKeyedService* BuildServiceInstanceFor(
      content::BrowserContext* profile) const OVERRIDE;
  virtual bool ServiceRedirectedInIncognito() const OVERRIDE;

  DISALLOW_COPY_AND_ASSIGN(GlobalErrorServiceFactory);
};

#endif  // CHROME_BROWSER_UI_GLOBAL_ERROR_GLOBAL_ERROR_SERVICE_FACTORY_H_
