// Copyright Rain


#include "UI/Widget/RainUserWidget.h"

void URainUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
