// Last updated: 6/7/2025, 5:39:20 PM
/**
 * @param {number} millis
 * @return {Promise}
 */

async function sleep(millis) {
    await new Promise(resolve => setTimeout(resolve, millis))
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */