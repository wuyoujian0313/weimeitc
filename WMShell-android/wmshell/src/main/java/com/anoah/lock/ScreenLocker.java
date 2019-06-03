package com.anoah.lock;

import java.io.File;

import android.content.Context;
import android.content.Intent;

public class ScreenLocker {
	private final static String LOCK = "com.anoah.action.lock";
	private final static String NOAHFILE = "/system/framework/com.noahedu.jar";

	private Context context;
	private LockKeeper keeper;
	private boolean bLocked = false;

	private void doLock(boolean lock) {
		Intent i = new Intent(LOCK);
		i.putExtra("locked", lock);
		context.sendBroadcast(i);
	}

	private boolean isYouxuepai() {
		File file = new File(NOAHFILE);
		return file.exists();
	}

	public ScreenLocker(Context context) {
		this.context = context;
	}

	public void lock() {
		if (!isYouxuepai()) {
			return;
		}
		bLocked = true;
		doLock(true);
		if (keeper == null) {
			keeper = new LockKeeper();
			keeper.start();
		}
	}

	public void unlock() {
		if (!isYouxuepai()) {
			return;
		}
		bLocked = false;
		doLock(false);
		if (keeper != null) {
			keeper.interrupt();
			keeper = null;
		}
	}

	private class LockKeeper extends Thread {
		public void run() {
			while (bLocked) {
				try {
					Thread.sleep(2000);
				} catch (InterruptedException e) {
					break;
				}

				if (bLocked) {
					doLock(true);
				}
			}
		}
	}
}
