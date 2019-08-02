package com.weimeitc.wmshell;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.webkit.ValueCallback;
import android.webkit.WebView;

import com.ai.base.AIBaseActivity;
import com.ai.webplugin.AIWebViewBasePlugin;
import com.anoah.lock.ScreenLocker;

/**
 * author: wuyoujian
 * Date: 2018/12/19
 */
public class AIWebViewExtendPlugin extends AIWebViewBasePlugin {
    private ScreenLocker locker;
    public AIWebViewExtendPlugin(AIBaseActivity activity, WebView webView) {
        super(activity,webView);

        locker = new ScreenLocker(activity);
    }


    public void JN_QuitApp() {
        System.exit(0);
    }


    public void JN_Unlock() {
        if (locker != null) {
            locker.unlock();
        }
    }

    public void JN_QRcode() {
        Intent intent = new Intent();
        intent.setClass(getActivity(), ScanActivity.class);
        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        getActivity().startActivityForResult(this,intent,100);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, requestCode,data);
        if (requestCode == 100) {
            if (data != null) {
                String result = data.getStringExtra("result");
                this.callback("JN_QRcode", result, new ValueCallback<String>() {
                    @Override
                    public void onReceiveValue(String value) {

                    }
                });
            }
        }
    }
}
