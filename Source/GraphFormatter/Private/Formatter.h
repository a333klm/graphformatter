/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Howaajin. All rights reserved.
 *  Licensed under the MIT License. See License in the project root for license information.
 *--------------------------------------------------------------------------------------------*/

#pragma once

#include "CoreMinimal.h"
#include "Layout/SlateRect.h"

class FBlueprintEditor;
class FMaterialEditor;
class FSoundCueEditor;
class FBehaviorTreeEditor;

struct FFormatter
{
    void SetCurrentEditor(UObject* Object, IAssetEditorInstance* Instance);
    bool IsAssetSupported(UObject* Object) const;

    inline bool IsVertical() const
    {
        return BehaviorTreeEditor != nullptr;
    }


    SGraphEditor* GetCurrentEditor() const;
    SGraphPanel* GetCurrentPanel() const;
    SGraphNode* GetWidget(const UEdGraphNode* Node) const;
    TSet<UEdGraphNode*> GetAllNodes() const;
    float GetCommentNodeTitleHeight(const UEdGraphNode* Node) const;
    FVector2D GetNodeSize(const UEdGraphNode* Node) const;
    FVector2D GetNodePosition(const UEdGraphNode* Node) const;
    FVector2D GetPinOffset(const UEdGraphPin* Pin) const;
    FSlateRect GetNodesBound(const TSet<UEdGraphNode*> Nodes) const;

    bool IsExecPin(const UEdGraphPin* Pin) const;

    void Translate(TSet<UEdGraphNode*> Nodes, FVector2D Offset);
    void UpdateCommentNodes() const;
    void SetZoomLevelTo11Scale() const;
    void RestoreZoomLevel() const;
    void Format() const;
    void PlaceBlock();
    static FFormatter& Instance()
    {
        static FFormatter Context;
        return Context;
    }

    FBlueprintEditor* BlueprintEditor = nullptr;
    FMaterialEditor* MaterialEditor = nullptr;
    FSoundCueEditor* SoundCueEditor = nullptr;
    FBehaviorTreeEditor* BehaviorTreeEditor = nullptr;

private:
    FFormatter() {}
    FFormatter(FFormatter const&) = delete;
    void operator=(FFormatter const&) = delete;

    SGraphEditor* CurrentEditor = nullptr;
};
