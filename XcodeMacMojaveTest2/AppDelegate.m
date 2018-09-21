#import "AppDelegate.h"
#import <OutlineViewTest/OutlineViewTest.h>
void DoMono (void);

@interface AppDelegate ()

@property (strong) LMOutlineViewTest* outlineViewTest;

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification*)aNotification
{
    DoMono ();

    self.outlineViewTest = [[LMOutlineViewTest alloc] init];
}

@end
