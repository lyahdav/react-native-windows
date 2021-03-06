// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include <Views/FrameworkElementViewManager.h>

namespace react::uwp {

class TextViewManager : public FrameworkElementViewManager {
  using Super = FrameworkElementViewManager;

 public:
  TextViewManager(const Mso::React::IReactContext &context);

  facebook::react::ShadowNode *createShadow() const override;

  const char *GetName() const override;

  void AddView(const XamlView &parent, const XamlView &child, int64_t index) override;
  void RemoveAllChildren(const XamlView &parent) override;
  void RemoveChildAt(const XamlView &parent, int64_t index) override;

  YGMeasureFunc GetYogaCustomMeasureFunc() const override;

  void OnDescendantTextPropertyChanged(ShadowNodeBase *node);

 protected:
  bool UpdateProperty(
      ShadowNodeBase *nodeToUpdate,
      const std::string &propertyName,
      const folly::dynamic &propertyValue) override;

  XamlView CreateViewCore(int64_t tag) override;
};

} // namespace react::uwp
